//
// Created by Mustafa Kemal Gökçe on 24.05.2023.
//

#include "deviceconnector.h"

int sendSignal(int signalNumber, int pinForIn, int pinForOut, int delayMs) {
    if(signalNumber == 1) {
        digitalWrite(pinForIn, LOW);
        delay(delayMs);
        digitalWrite(pinForIn, HIGH);
        printf("[+] %d sended.\n", pinForIn);
    }else if(signalNumber == 2) {
        digitalWrite(pinForOut, LOW);
        delay(delayMs);
        digitalWrite(pinForOut, HIGH);
        printf("[+] %d sended.\n", pinForOut);
    }else {
        printf("[!] Unknown signal number !");
    }
}

int writeLowForAllPins(int pinForIn, int pinForOut) {
    wiringPiSetup();
    pinMode(pinForIn, OUTPUT);
    pinMode(pinForOut, OUTPUT);
}
