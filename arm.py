
import smbus
import time
import struct
def floattoarray(w):
    a=bytearray(struct.pack("f",w))
    return [b for b in a]

bus = smbus.SMBus(1)

address = 0x04
def writeNumber(a,b,c):
        b.extend(c)
        bus.write_i2c_block_data(address,a,b)
        return -1

def readNumber():
        number=bus.read_i2c_block_data(address,0,6)
        return number
    
while True:
        data =[]
        n=[]
        for i in range(0,3):
            data.append(input("Enter the data to be sent : "))
        #data[0]=input("1st motor");
        #data[1]=input("1st motor");
        #data[2]=input("1st motor");
         
        writeNumber(data[0],floattoarray(data[1]),floattoarray(data[2]))
        print("data sent")
        #n=readNumber()
        time.sleep(0.2)
        #for i in range(0,6):
                #if n[i] is not 255:
                #n[i]=n[i]-48;
        #print("Data recieved is")
        #print(n)
