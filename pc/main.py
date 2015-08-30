import serial
import time


def main():
    romeo = serial.Serial('/dev/ttyACM0', 57600)
    count = 0
    oldLine = ""
    while True:
        line = romeo.readline()
        if len(line) > 0 and line != oldLine:
            print(str(time.time()) + ": " + line)
            oldLine = line
        count += 1
        # if count == 100:
        #     romeo.write("200 200")


main()
