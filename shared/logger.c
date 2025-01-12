#include "logger.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

typedef struct logger {
    FILE *file;
    bool debug;
} logger_t;
static logger_t logger;

int logger_init(bool debug)
{
    logger.debug = debug;
    logger.file = fopen("server.log", "a");
    if (!logger.file) {
        fprintf(stderr, "Failed to initialize logger\n");
        return 1;
    }
    return 0;
}

void logger_destroy()
{
    if (logger.file) {
        fclose(logger.file);
        logger.file = NULL;
    }
}

static void logger_write_message(const char *type, const char *message)
{
    if (!logger.file) {
        fprintf(stderr, "Logger is not initialized\n");
        return;
    }
    char time_buffer[32];
    time_t now = time(NULL);
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", localtime(&now));
    fprintf(logger.file, "%s => [%s] %s\n", type, time_buffer, message);
    fflush(logger.file);
    if (logger.debug) {
        fprintf(stderr, "%s => [%s] %s\n", type, time_buffer, message);
    }
}

void logger_write_info(const char *message)
{
    logger_write_message("INFO", message);
}

void logger_write_warning(const char *message)
{
    logger_write_message("WARNING", message);
}

void logger_write_error(const char *message)
{
    logger_write_message("ERROR", message);
}

