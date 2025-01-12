#ifndef LOGGER_H
#define LOGGER_H

#include <stdbool.h>

int logger_init(bool debug);
void logger_destroy();
static void logger_write_message(const char *type, const char *message);
void logger_write_info(const char *message);
void logger_write_warning(const char *message);
void logger_write_error(const char *message);

#endif // LOGGER_H
