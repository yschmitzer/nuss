#include "settings_menu.h"
#include <raylib.h>
#include <stdio.h>
#include "../scene_manager.h"

static int resolution_index = 0;
static const int resolutions[][2] = {
    {800, 600}, 
    {1024, 768}, 
    {1920, 1080}
};
static const int resolution_count = sizeof(resolutions) / sizeof(resolutions[0]);

void settings_menu_update() {
    if (IsKeyPressed(KEY_LEFT)) {
        resolution_index = (resolution_index - 1 + resolution_count) % resolution_count;
        SetWindowSize(resolutions[resolution_index][0], resolutions[resolution_index][1]);
    }
    if (IsKeyPressed(KEY_RIGHT)) {
        resolution_index = (resolution_index + 1) % resolution_count;
        SetWindowSize(resolutions[resolution_index][0], resolutions[resolution_index][1]);
    }
    if (IsKeyPressed(KEY_BACKSPACE)) {
        scene_manager_set_scene(SCENE_MAIN_MENU);
    }
}

void settings_menu_render() {
    char resolution_text[64];
    snprintf(resolution_text, sizeof(resolution_text), "Resolution: %dx%d",
             resolutions[resolution_index][0], resolutions[resolution_index][1]);
    DrawText(resolution_text, 10, 10, 20, DARKGRAY);
    DrawText("Press LEFT/RIGHT to change resolution", 10, 40, 20, DARKGRAY);
    DrawText("Press BACKSPACE to return to the main menu", 10, 70, 20, DARKGRAY);
}

