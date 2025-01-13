#include "logger.h"

static logger_t logger;

int logger_init(int debug_level)
{
    logger.debug_level = debug_level;
    logger.file = fopen("debug.log", "a");
    if (!logger.file) {
        fprintf(stderr, "Failed to initialize Logger\n");
        return true;
    }

    return false;
}

void logger_destroy()
{
    if (logger.file) {
        fclose(logger.file);
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
    fprintf(stderr, "%s => [%s] %s\n", type, time_buffer, message);
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

