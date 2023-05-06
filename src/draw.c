#include "sask/draw.h"

#include "sask/driver.h"

#define bwrite(a, x, y, c) a->buffer.pixels[(y * a->buffer.width) + x] = c;

void sask_draw_filled_rect(sask_app_t* app, u32 x1, u32 y1, u32 x2, u32 y2,
                           color_m color)
{
  u32 i, j;

  if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0) return;
  for (i = y1; i < y1 + y2; ++i)
  {
    for (j = x1; j < x1 + x2; ++j)
    {
      bwrite(app, j, i, color);
    }
  }
}
