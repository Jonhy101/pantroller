#include "devices.h"

QStringList Devices::getDevicesList() {
    return{
        "PIC16F628A","PIC16F877A", "PIC16F883",
        "PIC16F886", "PIC18F4550", "PIC18F2550",
        "PIC18F4553", "PIC18F45K22", "PIC18F45K50",
        "DSPIC33FJ129K200A"
    };
}
