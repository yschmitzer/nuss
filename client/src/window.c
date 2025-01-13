#include "../include/window.h"
#include "raylib.h"
#include "../include/server.h"

int window_init(window_t *window, int width, int height, const char *title)
{
    window->should_close = false;
    window->width = width;
    window->height = height;
    InitWindow(width, height, title);
    while (!IsWindowReady()) {}
    SetExitKey(KEY_NULL);
    return 0;
}

void window_input(window_t *window, server_t *server)
{
    if (WindowShouldClose()) {
        window->should_close = true;
    }
    if (IsKeyPressed(KEY_P)) {
        if (!server->peer) {
            server_connect(server, "127.0.0.1", 6942);
        } else {
            if (server->client) {
                server_disconnect(server);
            }
        }
    }
}

void window_update(window_t *window)
{
}

void window_render(window_t *window)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
}

void window_destroy(window_t *window)
{
    CloseWindow();
}
