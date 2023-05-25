//
// Created by Mustafa Kemal Gökçe on 24.05.2023.
//

#include "deviceconnector.h"

int sendSignal(int signalNumber) {
    if(signalNumber == 1) {
        digitalWrite(NUM1, LOW);
        delay(1000);
        digitalWrite(NUM1, HIGH);
        printf("[+] %d sended.\n", NUM1);
    }else if(signalNumber == 2) {
        digitalWrite(NUM2, LOW);
        delay(1000);
        digitalWrite(NUM2, HIGH);
        printf("[+] %d sended.\n", NUM2);
    }else {
        printf("[!] Unknown signal number !");
    }
}

int writeLowForAllPins() {
    wiringPiSetup();
    pinMode(NUM1, OUTPUT);
    pinMode(NUM2, OUTPUT);
}
