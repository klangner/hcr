# Arduino Make file. Refer to https://github.com/sudar/Arduino-Makefile

BOARD_TAG    = uno
ARDUINO_PORT = /dev/ttyACM0
ARDUINO_DIR  = /home/klangner/bin/arduino-1.6.5
OBJDIR       = ../build-$(BOARD_TAG)
#MONITOR_BAUDRATE  = 115200

### CFLAGS_STD
CFLAGS_STD        = -std=gnu11

### CXXFLAGS_STD
CXXFLAGS_STD      = -std=gnu++11

### CPPFLAGS
### Flags you might want to set for debugging purpose. Comment to stop.
CXXFLAGS         = -pedantic -Wall -Wextra

### If avr-gcc -v is higher than 4.9, activate coloring of the output
ifeq "$(AVR_GCC_VERSION)" "1"
    CXXFLAGS += -fdiagnostics-color
endif

include ../../Arduino-Makefile/Arduino.mk
