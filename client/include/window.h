#pragma once

#include "server.h"
#include "logger.h"
#include <stdbool.h>
#include <raylib.h>

typedef struct window {
    bool should_close;
    int width;
    int height;
} window_t;

int window_init(window_t *window, int width, int height, const char *title);
void window_input(window_t *window, server_t *server);
void window_update(window_t *window);
void window_render(window_t *window);
void window_destroy(window_t *window);
