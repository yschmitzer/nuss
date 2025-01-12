#include "server_menu.h"
#include <raylib.h>
#include "../scene_manager.h"
#include "../server.h"

void server_menu_update() {
    if (IsKeyPressed(KEY_C)) {
        server_connect("127.0.0.1", 6942);  // Example: Connect to localhost
    }
    if (IsKeyPressed(KEY_ENTER)) {
        scene_manager_set_scene(SCENE_WORLD);
    }
}

void server_menu_render() {
    DrawText("Server Menu - Press C to connect, ENTER to load world", 10, 10, 20, DARKGRAY);
}

