#ifndef WINDOW_H
#define WINDOW_H

#include <stdbool.h>
#include <raylib.h>

bool window_init(int width, int height, const char *title);
void window_refresh();
bool window_should_close();
void window_destroy();

#endif // WINDOW_H
