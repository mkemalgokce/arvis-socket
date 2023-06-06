
#ifndef ARVIS_SOCKET_GLOBALS_H
#define ARVIS_SOCKET_GLOBALS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ini.h"

struct Settings {
    int pinForOut;
    int pinForIn;
    int port;
    int delayMs;
}settings;

static int handler(void* user, const char* section, const char* name, const char* value);

void readIniFile(const char* filename);

#endif //ARVIS_SOCKET_GLOBALS_H