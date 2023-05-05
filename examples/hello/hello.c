#include <sask/driver.h>
#include <stdio.h>

/* Experimental, this example is for testing */

int main(void)
{
  if (!driver_init())
  {
    printf("Unable to initialize SDL: %s\n", driver_error());
    return 1;
  }

  color_t RED = {.r = 255, .g = 0, .b = 0, .a = 255};

  void *nwindow = driver_create_window("pretty", 0, 0, 800, 420);
  void *nrender = driver_create_renderer(nwindow);

  driver_render_clear(nrender);
  driver_render_set_color(nrender, RED);
  driver_render_rect(nrender, 0, 0, 100, 100);
  driver_render_present(nrender);

  driver_delay(5 * 1000);

  driver_destroy_renderer(nrender);
  driver_destroy_window(nwindow);

  return 0;
}