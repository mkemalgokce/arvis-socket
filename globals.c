#include "globals.h"

static int handler(void* user, const char* section, const char* name, const char* value){
    if (strcmp(section, "Globals") == 0) {
        printf("Here !");
        if (strcmp(name, "pinForOut") == 0) {
            settings.pinForOut = atoi(value);
        }
        else if (strcmp(name, "pinForIn") == 0) {
            settings.pinForIn = atoi(value);
        } else if (strcmp(name, "port") == 0) {
            settings.port = atoi(value);
        } else if (strcmp(name, "delayMs") == 0) {
            settings.delayMs = atoi(value);
        }
    }
    return 1;
}

void readIniFile(const char* filename) {
    if (ini_parse(filename, handler, NULL) < 0) {
        printf("Ini dosyası okuma hatası: %s\n", filename);
    }
}

