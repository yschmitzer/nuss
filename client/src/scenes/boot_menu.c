#include "boot_menu.h"
#include <raylib.h>
#include "../scene_manager.h"

void boot_menu_update() {
    if (IsKeyPressed(KEY_ENTER)) {
        scene_manager_set_scene(SCENE_MAIN_MENU);
    }
}

void boot_menu_render() {
    DrawText("Boot Menu - Press ENTER to continue", 10, 10, 20, DARKGRAY);
}
