#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

typedef struct logger {
    int debug_level;
    FILE *file;
} logger_t;

int logger_init(int debug_level);
void logger_destroy();

static void logger_write_message(const char *type, const char *message);
void logger_write_info(const char *message);
void logger_write_warning(const char *message);
void logger_write_error(const char *message);
