#The main script for programming binaries to the EEPROM
#Copyright (C) 2023  Tristan van de Weg & Marijn Vollenberg
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License along
#    with this program; if not, write to the Free Software Foundation, Inc.,
#    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

import binprog
import ProgrammerUI
import wx
import configparser
from os.path import exists

serialBaud = 115200
serialPort = ""
filename = ""
configPath = __file__[:-3]+".cfg"                                   #Fix file extension for config file
config = configparser.ConfigParser()

class MainUI(ProgrammerUI.Main):                                    #Functionality for the main menu
    def __init__(self, *args, **kwds):
        ProgrammerUI.Main.__init__(self, *args, **kwds)
        if exists(configPath):                                      #Open the config file if it exists
            config.read(configPath)
        else:                                                       #Create a new config file if it doesn't exist
            with open(configPath, "w") as configFile:
                config.add_section("connection")
                config.set("connection", "port", "/dev/ttyUSB0")
                config.set("connection", "baudrate", "115200")
                config.set("connection", "save", "true")
                config.add_section("licence")
                config.set("licence", "hide", "false")
                config.write(configFile)
                configFile.flush()
                configFile.close()
        self.licenceUI = LicenceUI(self, wx.ID_ANY, "")             #Initialize the licence message box

    def OnFileSelect(self, event):                                  #Functionality for the file select button
        global filename
        dlg = wx.FileDialog(self, message="Choose Binary")          #File selection popup
        if dlg.ShowModal() == wx.ID_OK:
            filename = dlg.GetPath()
            dlg.Destroy()
        if filename != "":                                          #Set the filename in the menu and enable the write button if connected
            if len(filename) > 40:
                ProgrammerInterface.frame.SelectedFile.SetLabel("..."+filename[-40:])
            else:
                ProgrammerInterface.frame.SelectedFile.SetLabel(filename)
            if binprog.serConnected:
                self.Write.Enable(True)

    def OnWrite(self, event):                                       #Functionality for the write button
        file = binprog.readFile(filename)   #TODO test this
        print("Starting write")
        binprog.bulkWrite(filename)
        print("Finished writing, verifying")
        ver = binprog.read()
        count = 0
        for i in range(0,len(file)):
            if file[i]==ver[i]:
                count += 1
                if count==10:
                    print(".","","")
                    count = 0
            else:
                print("\nError at byte "+i)
        print("Done")


    def OnRead(self, event):                                        #Functionality for the read button
        dlg = wx.MessageDialog(self.panel_1, binprog.read(), "EEPROM Contents")
        dlg.ShowModal()

    def OnSerialPortSettings(self, event):                          #Serial settings menu button
        self.SerialSelect = SerialSelectUI(None, wx.ID_ANY, "")
        self.SerialSelect.Show()



class SerialSelectUI(ProgrammerUI.SerialSelect):                    #Functionality for the serial settings menu
    def __init__(self, *args, **kwds):
        ProgrammerUI.SerialSelect.__init__(self, *args, **kwds)
        if config["connection"]["save"] == "false":                 #Load save config setting for checkbox
            self.checkbox.SetValue(False)
        else:
            self.checkbox.SetValue(True)

    def OnSerialConnect(self, event):                               #Event handler for the connect button
        binprog.connectSerial(self.SerialPort.GetLineText(0), int(self.SerialBaudRate.GetStringSelection()))
        if binprog.serConnected:
            global serialBaud
            global serialPort
            serialBaud = self.SerialBaudRate.GetStringSelection()
            serialPort = self.SerialPort.GetLineText(0)

            if self.checkbox.GetValue():                            #Save the connection config
                config.set("connection", "port", serialPort)
                config.set("connection", "baudrate", serialBaud)
                config.set("connection", "save", "true")
            else:
                config.set("connection", "save", "false")
            with open(configPath, "w") as configFile:
                config.write(configFile)
                configFile.flush()
                configFile.close()

            ProgrammerInterface.frame.CurSerialBaud.SetLabel(serialBaud)
            ProgrammerInterface.frame.CurSerialPort.SetLabel(serialPort)
            ProgrammerInterface.frame.Read.Enable(True)
            if filename:
                ProgrammerInterface.frame.Write.Enable(True)
            self.Destroy()

class LicenceUI(ProgrammerUI.Licence):                              #Licence popup
    def __init__(self, *args, **kwds):
        ProgrammerUI.Licence.__init__(self, *args, **kwds)

    def OnLicenceDisagree(self, event):
        ProgrammerInterface.ExitMainLoop()

    def OnLicenceAgree(self, event):
        if self.NoLicence.GetValue:
            config.set("licence", "hide", "true")

            with open(configPath, "w") as configFile:
                config.write(configFile)
                configFile.flush()
                configFile.close()
        self.Destroy()


class UI(wx.App):                                                   #Main App
    def OnInit(self):
        self.frame = MainUI(None, wx.ID_ANY, "")
        if config["licence"]["hide"] != "true":                     #Only show licence if it is not hidden in config
            self.SetTopWindow(self.frame.licenceUI)
            self.frame.licenceUI.Show()
        self.frame.Show()
        return True

if __name__ == "__main__":                                          #Startup script
    ProgrammerInterface = UI(0)
    if config["connection"]["save"]=="true":                        #Attempt to connect to serial on saved port and baudrate
        binprog.connectSerial(config["connection"]["port"],int(config["connection"]["baudrate"]))
    if binprog.serConnected:                                        #Set variables if connection was successful
        serialBaud = config["connection"]["baudrate"]
        serialPort = config["connection"]["port"]
        ProgrammerInterface.frame.CurSerialBaud.SetLabel(str(serialBaud))
        ProgrammerInterface.frame.CurSerialPort.SetLabel(serialPort)
        ProgrammerInterface.frame.Read.Enable(True)
    ProgrammerInterface.MainLoop()