#include "window.h"
#include "raylib.h"

bool window_init(int width, int height, const char *title) {
    InitWindow(width, height, title);
    SetExitKey(KEY_F12);
    return !WindowShouldClose();
}

void window_refresh() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
}

bool window_should_close() {
    return WindowShouldClose();
}

void window_destroy() {
    CloseWindow();
}
