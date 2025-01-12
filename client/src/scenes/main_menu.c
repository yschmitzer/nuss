#include "main_menu.h"
#include <raylib.h>
#include "../scene_manager.h"

void main_menu_update() {
    if (IsKeyPressed(KEY_S)) {
        scene_manager_set_scene(SCENE_SERVER_MENU);
    }
}

void main_menu_render() {
    DrawText("Main Menu - Press S to go to server menu", 10, 10, 20, DARKGRAY);
}
