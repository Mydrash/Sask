#include <sask/driver.h>
#include <sask/keyboard.h>
#include <stdio.h>
#include <string.h>

/* Experimental, this example is for testing */
color_t RED = {.r = 255, .g = 0, .b = 0, .a = 255};

int main(void)
{
  device_framebuffer_t buffer;
  void *nwindow, *render;

  if (!driver_init())
  {
    printf("Unable to initialize SDL: %s\n", driver_error());
    return 1;
  }

  nwindow = driver_window_create("Unpretty", 0, 0, 800, 420);
  render = driver_renderer_create(nwindow);
  buffer = driver_render_create_buffer(render, 800, 420);

loop:
  for (size_t ps = 0; ps < (buffer.width * buffer.height); ++ps)
  {
    buffer.pixels[ps] = RED;
  }

  driver_render_clear(render);

  if (!driver_render_buffer(render, &buffer))
  {
    printf("SDL error: %s\n", driver_error());
    goto exit;
  }

  driver_render_present(render);

  union driver_event ev = driver_poll_event();

  switch (ev.type)
  {
  case DRIVER_EVENT_QUIT_REQUESTED:
    goto exit;
  case DRIVER_EVENT_KEYCHANGED:
    if (ev.key.code == KEY_ESCAPE)
      goto exit;
  }

  goto loop;

exit:
  driver_destroy_buffer(&buffer);
  driver_destroy_renderer(render);
  driver_destroy_window(nwindow);

  return 0;
}