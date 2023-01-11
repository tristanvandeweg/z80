#Copyright (C) 2022  Tristan van de Weg
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
import sys

connected = False
serialBaud = 0
serialPort = ""

class MainUI(ProgrammerUI.Main):
    def __init__(self, *args, **kwds):
        ProgrammerUI.Main.__init__(self, *args, **kwds)
    
    def OnFileSelect(self, event):
        global filename
        filename = ""
        dlg = wx.FileDialog(self, message="Choose Binary")
        if dlg.ShowModal() == wx.ID_OK:
            filename = dlg.GetPath()
            dlg.Destroy()
        if filename:
            ProgrammerInterface.frame.SelectedFile.SetLabel(filename)
            if connected:
                self.Write.Enable(True)
    
    def OnWrite(self, event):
        print("Event handler 'OnWrite' not implemented!")
        print(binprog.readFile(filename))
        event.Skip()

    def OnRead(self, event):
        dlg = wx.MessageDialog(self.panel_1, binprog.read(), "EEPROM Contents")
        dlg.ShowModal()

    def OnSerialPortSettings(self, event):
        self.SerialSelect = SerialSelectUI(None, wx.ID_ANY, "")
        self.SerialSelect.Show()

class SerialSelectUI(ProgrammerUI.SerialSelect):
    def __init__(self, *args, **kwds):
        ProgrammerUI.SerialSelect.__init__(self, *args, **kwds)

    def OnSerialConnect(self, event):
        #binprog.connectSerial(self.SerialPort.GetLineText(0), int(self.SerialBaudRate.GetStringSelection()))
        if True: #binprog.ser.is_open
            global serialBaud
            global serialPort
            global connected
            serialBaud = self.SerialBaudRate.GetStringSelection()
            serialPort = self.SerialPort.GetLineText(0)
            connected = True

            if connected:
                ProgrammerInterface.frame.CurSerialBaud.SetLabel(serialBaud)
                ProgrammerInterface.frame.CurSerialPort.SetLabel(serialPort)
                ProgrammerInterface.frame.Read.Enable(True)
                if filename:
                    ProgrammerInterface.frame.Write.Enable(True)
            self.Destroy()


class UI(wx.App):
    def OnInit(self):
        self.frame = MainUI(None, wx.ID_ANY, "")
        self.SetTopWindow(self.frame)
        self.frame.Show()
        return True

if __name__ == "__main__":
    ProgrammerInterface = UI(0)
    ProgrammerInterface.MainLoop()