//
// Created by Mustafa Kemal Gökçe on 24.05.2023.
//

#ifndef ARVIS_SOCKET_DEVICECONNECTOR_H
#define ARVIS_SOCKET_DEVICECONNECTOR_H

#include <stdio.h>
#include "globals.h"
#include <wiringPi.h>

int sendSignal(int signalNumber, int pinForIn, int pinForOut, int delayMs);
int writeLowForAllPins();

#endif //ARVIS_SOCKET_DEVICECONNECTOR_H
