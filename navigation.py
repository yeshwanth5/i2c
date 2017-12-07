
import smbus
import time

bus = smbus.SMBus(1)

address = 0x04
def writeNumber(a,b):
        bus.write_i2c_block_data(address,a,[b])
        return -1

def readNumber():
        number=bus.read_i2c_block_data(address,0,6)
        return number
    
while True:
        data =[]
        n=[]
        for i in range(0,2):
            data.append(input("Enter the data to be sent : "))
        writeNumber(data[0],data[1])
        print("data sent");
        n=readNumber()
        time.sleep(0.2)
        print("Data recieved is")
        print(n)
