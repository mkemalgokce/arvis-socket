//
// Created by Mustafa Kemal Gökçe on 24.05.2023.
//

#include "deviceconnector.h"

int sendSignal(int signalNumber) {
    if(num == 1) {
        digitalWrite(NUM1, HIGH);
        delay(1000);
        digitalWrite(NUM1, LOW);
        printf("[+] %d sended.\n", NUM1)
    }else if(num == 2) {
        digitalWrite(NUM2, HIGH);
        delay(1000);
        digitalWrite(NUM2, LOW);
        printf("[+] %d sended.\n", NUM2);
    }else {
        printf("[!] Unknown signal number !");
    }
}

int writeLowForAllPins() {
    wiringPiSetup();
    for(int i = 0; i < 26; ++i) {
        digitalWrite(i, LOW);
    }
}