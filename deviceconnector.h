//
// Created by Mustafa Kemal Gökçe on 24.05.2023.
//

#ifndef ARVIS_SOCKET_DEVICECONNECTOR_H
#define ARVIS_SOCKET_DEVICECONNECTOR_H

#include <stdio.h>
#include <wiringPi.h>

#define NUM1 9
#define NUM2 10

int sendSignal(int signalNumber);
int writeLowForAllPins();

#endif //ARVIS_SOCKET_DEVICECONNECTOR_H
