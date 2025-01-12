#include "world_scene.h"
#include <raylib.h>
#include "../scene_manager.h"
#include "../server.h"

void world_scene_update() {
    // Example: Handle input to return to the main menu
    if (IsKeyPressed(KEY_ESCAPE)) {
        server_disconnect();
        scene_manager_set_scene(SCENE_MAIN_MENU);
    } else {
        // Update server communication
        server_update();
    }
}

void world_scene_render() {
    DrawText("World Scene - Press ESC to return to main menu", 10, 10, 20, DARKGRAY);
    DrawRectangle(100, 100, 200, 200, BLUE); // Example: Render a "world block"
}

