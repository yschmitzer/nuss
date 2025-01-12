#include <stdio.h>
#include <stdbool.h>
#include <raylib.h>

int main() {
    // Initialize the window
    InitWindow(800, 600, "Client Test");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    // Simple game loop
    while (!WindowShouldClose()) {
        // Update logic
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Hello, Client!", 350, 280, 20, BLACK);

        EndDrawing();
    }

    // Cleanup
    CloseWindow();
    return 0;
}
