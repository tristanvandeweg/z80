
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


#!/usr/bin/env python3.9
# -*- coding: UTF-8 -*-
#
# generated by wxGlade 1.0.2 on Sun Nov 28 18:05:58 2021
#

import binprog
import wx

# begin wxGlade: dependencies
# end wxGlade

# begin wxGlade: extracode
# end wxGlade


class SerialSelect(wx.Frame):
	def __init__(self, *args, **kwds):
		# begin wxGlade: SerialSelect.__init__
		kwds["style"] = kwds.get("style", 0) | wx.DEFAULT_FRAME_STYLE
		wx.Frame.__init__(self, *args, **kwds)
		self.SetSize((300, 120))
		self.SetTitle("Serial Port Settings")

		self.panel_1 = wx.Panel(self, wx.ID_ANY)

		sizer_1 = wx.BoxSizer(wx.VERTICAL)

		self.SerialPort = wx.TextCtrl(self.panel_1, wx.ID_ANY, "/dev/ttyUSB0")
		self.SerialPort.SetMinSize((300, 32))
		self.SerialPort.SetToolTip("Serial Port of the programmer")
		sizer_1.Add(self.SerialPort, 0, wx.EXPAND, 0)


		self.SerialBaudRate = wx.TextCtrl(self.panel_1, wx.ID_ANY, "19200")
		self.SerialBaudRate.SetMinSize((300, 32))
		self.SerialBaudRate.SetToolTip("Baudrate")
		sizer_1.Add(self.SerialBaudRate, 0, wx.EXPAND, 0)
		#self.SerialBaudRate = wx.ComboBox(self.panel_1, wx.ID_ANY, choices=["Baudrate", "19200", "9600"], style=wx.CB_DROPDOWN)
		#sizer_1.Add(self.SerialBaudRate, 0, wx.EXPAND, 0)

		self.SerialConnect = wx.Button(self.panel_1, wx.ID_ANY, "Connect to serial port")
		sizer_1.Add(self.SerialConnect, 0, wx.EXPAND, 0)

		self.panel_1.SetSizer(sizer_1)

		self.Layout()

		self.Bind(wx.EVT_BUTTON, self.OnSerialConnect, self.SerialConnect)
		# end wxGlade

	def OnSerialConnect(self, event):  # wxGlade: SerialSelect.<event_handler>
		binprog.connectSerial(self.SerialPort.GetLineText(0), self.SerialBaudRate.GetLineText(0))
		if binprog.ser.is_open:
			ProgrammerInterface.Main.CurSerialBaud.SetLabel(self.SerialBaudRate.GetLineText(0))
			ProgrammerInterface.Main.CurSerialPort.SetLabel(self.SerialPort.GetLineText(0))
			ProgrammerInterface.Main.Read.Enable(True)
		self.Destroy()

# end of class SerialSelect

class Main(wx.Frame):
	def __init__(self, *args, **kwds):
		# begin wxGlade: Main.__init__
		kwds["style"] = kwds.get("style", 0) | wx.DEFAULT_FRAME_STYLE
		wx.Frame.__init__(self, *args, **kwds)
		self.SetSize((600, 250))
		self.SetTitle("z80 Programmer")

		self.panel_1 = wx.Panel(self, wx.ID_ANY)

		sizer_1 = wx.BoxSizer(wx.VERTICAL)

		sizerFileSelect = wx.StaticBoxSizer(wx.StaticBox(self.panel_1, wx.ID_ANY, "File Selection"), wx.HORIZONTAL)
		sizer_1.Add(sizerFileSelect, 1, wx.EXPAND, 0)

		self.FileSelect = wx.Button(self.panel_1, wx.ID_ANY, "Select File")
		sizerFileSelect.Add(self.FileSelect, 0, wx.ALIGN_CENTER_VERTICAL, 0)

		self.SelectedFile = wx.StaticText(self.panel_1, wx.ID_ANY, "Selected File")
		sizerFileSelect.Add(self.SelectedFile, 0, wx.ALIGN_CENTER_VERTICAL | wx.ALL, 7)

		ProgrammingControls = wx.StaticBoxSizer(wx.StaticBox(self.panel_1, wx.ID_ANY, "Programming"), wx.HORIZONTAL)
		sizer_1.Add(ProgrammingControls, 1, wx.EXPAND, 0)

		self.Write = wx.Button(self.panel_1, wx.ID_ANY, "Write")
		self.Write.Enable(False)
		ProgrammingControls.Add(self.Write, 1, wx.ALIGN_CENTER_VERTICAL | wx.ALL, 1)

		self.Read = wx.Button(self.panel_1, wx.ID_ANY, "Read")
		self.Read.Enable(False)
		ProgrammingControls.Add(self.Read, 1, wx.ALIGN_CENTER_VERTICAL | wx.ALL, 1)

		sizer_2 = wx.StaticBoxSizer(wx.StaticBox(self.panel_1, wx.ID_ANY, "Serial Port Settings"), wx.HORIZONTAL)
		sizer_1.Add(sizer_2, 1, wx.EXPAND, 0)

		CurSerialSettings = wx.BoxSizer(wx.VERTICAL)
		sizer_2.Add(CurSerialSettings, 2, wx.ALIGN_CENTER_VERTICAL, 0)

		self.CurSerialPort = wx.StaticText(self.panel_1, wx.ID_ANY, "Serial Port")
		CurSerialSettings.Add(self.CurSerialPort, 0, wx.EXPAND, 0)

		self.CurSerialBaud = wx.StaticText(self.panel_1, wx.ID_ANY, "Baudrate")
		CurSerialSettings.Add(self.CurSerialBaud, 0, wx.EXPAND, 0)

		self.SetSerialSettings = wx.Button(self.panel_1, wx.ID_ANY, "Settings")
		sizer_2.Add(self.SetSerialSettings, 1, wx.ALIGN_CENTER_VERTICAL, 0)

		self.panel_1.SetSizer(sizer_1)

		self.Layout()

		self.Bind(wx.EVT_BUTTON, self.OnFileSelect, self.FileSelect)
		self.Bind(wx.EVT_BUTTON, self.OnWrite, self.Write)
		self.Bind(wx.EVT_BUTTON, self.OnRead, self.Read)
		self.Bind(wx.EVT_BUTTON, self.OnSerialPortSettings, self.SetSerialSettings)
		# end wxGlade

	def OnFileSelect(self, event):  # wxGlade: Main.<event_handler>
		filename = ""
		dlg = wx.FileDialog(self, message="Choose Binary")
		if dlg.ShowModal() == wx.ID_OK:
			filename = dlg.GetPath()
		dlg.Destroy()
		if filename:
			self.SelectedFile.SetLabel(filename)
			if binprog.ser.is_open:
				self.Write.Enable(True)

	def OnWrite(self, event):  # wxGlade: Main.<event_handler>
		print("Event handler 'OnWrite' not implemented!")
		event.Skip()

	def OnRead(self, event):  # wxGlade: Main.<event_handler>
		dlg = wx.MessageDialog(self.panel_1, binprog.read(), "EEPROM Contents")
		dlg.ShowModal()

	def OnSerialPortSettings(self, event):  # wxGlade: Main.<event_handler>
		self.SerialSelect = SerialSelect(None, wx.ID_ANY, "")
		self.SerialSelect.Show()

# end of class Main

class ProgInterface(wx.App):
	def OnInit(self):
		self.Main = Main(None, wx.ID_ANY, "")
		self.SetTopWindow(self.Main)
		self.Main.Show()
		return True

# end of class ProgInterface

if __name__ == "__main__":
	ProgrammerInterface = ProgInterface(0)
	ProgrammerInterface.MainLoop()
