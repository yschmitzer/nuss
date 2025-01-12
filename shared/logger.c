#include "logger.h"
#include <stdio.h>
#include <string.h>

const char* FormatMessage(const char *msg) {
    static char buffer[256];
    snprintf(buffer, sizeof(buffer), "MSG: %s", msg);
    return buffer;
}

