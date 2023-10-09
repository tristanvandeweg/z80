#Backend for the EEPROM programming tool
#Copyright (C) 2022-2023  Tristan van de Weg
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

import serial
import sys
from time import sleep
from io import StringIO
from contextlib import redirect_stdout
import re

serConnected = False
ser = serial.Serial()
ser.timeout = 1
rd = "Nothing read yet"

def connectSerial(_port, _baud):                                #Connect to the specified serial port
    if ser.is_open==True:                                       #Close the serial port if it is open already
        ser.close()
    ser.port = _port                                            #Set port and speed
    ser.baudrate = _baud
    print("Attempting to connect to "+_port+" at "+str(_baud)+" baud")
    try:
        ser.open()                                              #Attempt to connect
        if ser.is_open==True:                                   #Return if the connection was successful
            serConnected = True
    except serial.serialutil.SerialException as err:            #Print error message if the connection failed
        print(err)
        serConnected = False

def writeByte(_addr1, _addr2, _data):                           #Write a single byte to a specified address
    ser.write(bytearray(b'\x77\x0D\x0A'))                       #In ASCII: w CR LF
    sleep(.5)
    ser.write(bytearray([b'\x41', _addr1, _addr2, b'\x0D\x0A']))#In ASCII: A <Address> CR LF
    sleep(.5)
    ser.write(bytearray([b'\x44', _data, b'\x0D\x0A']))         #In ASCII: D <Data> CR LF
    sleep(.5)
    ser.write(bytearray(b'\x57\x0D\x0A'))                       #In ASCII: W CR LF
    sleep(.5)

def read():                                                     #Read the entire EEPROM
    ser.write(bytearray(b'\x52\x0D\x0A'))                       #In ASCII: R CR LF
    #sleep(1)#TODO test this
    o = ser.read(27500)                                         #Read the next 27500 bytes
    #with redirect_stdout(StringIO()) as f:
    contents = re.split(',\n\r',o)                              #Convert the CSV into an array
    for i in range(0,len(contents)):#TODO Parsing of info
        contents[i].decode("ascii")
    print(o.decode("ascii"))                                    #Convert the result into hexadecimal
    #rd = f.getvalue()
    return o.decode("ascii")

def readFile(_filename):    #Load a binary file for writing
    filearray = []
    with open(_filename, mode="rb") as file:
        while (byte := file.read(1)):
            filearray.append(byte)
        return filearray
    
def bulkWrite(_filename):   #Write a binary file to the entire EEPROM
    binFile = readFile(_filename) #TODO add this

    ser.write(bytearray(b'\x62\x0D\x0A'))
    sleep(.05)
    ser.write(bytearray(b'\x56\x0D\x0A'))
    ser.write(bytearray([b'\x42',8192,b'\x0D\x0A']))
    sleep(.05)
    for i in binFile:
        ser.write(bytearray([i,b'\x0D\x0A']))

if __name__=='__main__':
    sys.exit()
