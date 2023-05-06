#include "sask/driver.h"
#include "sask/engine.h"

#ifndef _sask_draw

/*
 * Draws a filled rect.
 */
void sask_draw_filled_rect(sask_app_t* app, u32 x1, u32 y1, u32 x2, u32 y2,
                           color_m color);

#define _sask_draw
#endif
