import serial
import sys
from time import sleep
from io import StringIO
from contextlib import redirect_stdout

serConnected = False
ser = serial.Serial()
ser.timeout = 1
rd = "Nothing read yet"

def connectSerial(_port, _baud):
    if ser.is_open==True:
        ser.close()
    ser.port = _port
    ser.baudrate = _baud
    ser.open()
    if ser.is_open==True:
        serConnected = True

def writeByte(_addr1, _addr2, _data):
    ser.write(bytearray(b'\x77\x0D\x0A'))
    sleep(.5)
    ser.write(bytearray([b'\x41', _addr1, _addr2, b'\x0D\x0A']))
    sleep(.5)
    ser.wire(bytearray([b'\x44', _data, b'\x0D\x0A']))
    sleep(.5)
    ser.write(bytearray(b'\x57\x0D\x0A'))
    sleep(.5)

def read():
    ser.write(bytearray(b'\x52\x0D\x0A'))
    #sleep(1)
    o = ser.read(1000)
    #with redirect_stdout(StringIO()) as f:
    print(o.decode("ascii"))
    #rd = f.getvalue()
    return o.decode("ascii")

if __name__=='__main__':
    sys.exit()
