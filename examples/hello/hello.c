#include <stdio.h>

#include "sask/draw.h"
#include "sask/engine.h"
#include "sask/keyboard.h"

/* Experimental, this example is for testing */

int main(void)
{
  sask_app_t app;
  color_t RED = {.r = 0xFF, .g = 0x00, .b = 0x00, .a = 0xFF};
  u32 x = 0, y = 0;

  if (sask_init() != SASK_OK)
  {
    printf("Unable to initialize engine: %s", sask_error());
    return 1;
  }

  if (!sask_app_create(&app, "Sask App: Hello", 0, 0, 800, 420))
  {
    printf("Unable to create application: %s\n", sask_error());
    sask_destroy();
    return 1;
  }

  do
  {
    if (sask_keyboard_pressed(&app, KEY_ESCAPE))
    {
      goto exit;
    }

    if (sask_keyboard_pressed(&app, KEY_a)) x -= 1;
    if (sask_keyboard_pressed(&app, KEY_d)) x += 1;
    if (sask_keyboard_pressed(&app, KEY_w)) y -= 1;
    if (sask_keyboard_pressed(&app, KEY_s)) y += 1;

    if (x <= 0 || x >= 800 || y <= 0 || y >= 420)
    {
      x = 0;
      y = 0;
    }

    printf("%d, %d\n", x, y);
    if (app.should_quit)
    {
      goto exit;
    }

    sask_draw_filled_rect(&app, x, y, 200, 200, RED);

    sask_app_next(&app);
  } while (1);

exit:
  sask_app_destroy(&app);
  sask_destroy();
  return 0;
}
