
import smbus
import time

bus = smbus.SMBus(1)

address = 0x04
def writeNumber(a,b,c):
        bus.write_i2c_block_data(address,a,[b,c])
        return -1

def readNumber():
        number=bus.read_i2c_block_data(address,0,4)
        return number
    
while True:
        data =[]
        n=[]
        for i in range(0,3):
            data.append(input("Enter the data to be sent : "))
        writeNumber(data[0],data[1],data[2])
        print("data sent");
        n=readNumber()
        time.sleep(0.2)
        for i in range(0,4):
                if n[i] is not 255:
                        n[i]=n[i]-48;
        print("Data recieved is")
        print(n)
