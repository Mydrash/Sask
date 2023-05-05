#include <sask/driver.h>
#include <sask/keyboard.h>
#include <stdio.h>
#include <string.h>

/* Experimental, this example is for testing */

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
  color_t bg = {.r = 255, .g = 0, .b = 0, .a = 255};

loop:
  for (size_t ps = 0; ps < (buffer.width * buffer.height); ++ps)
  {
    buffer.pixels[ps] = bg;
  }

  driver_render_clear(render);

  if (!driver_render_buffer(render, &buffer))
  {
    printf("SDL error: %s\n", driver_error());
    goto exit;
  }

  driver_render_present(render);

  struct driver_event ev = driver_poll_event();

  switch (ev.type)
  {
  case DRIVER_EVENT_QUIT_REQUESTED:
    puts("quitting!");
    goto exit;
  case DRIVER_EVENT_KEYCHANGED:
    switch (ev.data.key.code)
    {
    case KEY_a:
      ++bg.g;
      break;
   
    case KEY_d:
      ++bg.b;
      break;

    case KEY_p:
        printf("0x%X: (r: %d, g: %d, b: %d)\n", bg.value, bg.r, bg.g, bg.b);
        break;
        
    case KEY_ESCAPE:
      goto exit;
    }
  }

  goto loop;
exit:
  driver_destroy_buffer(&buffer);
  driver_destroy_renderer(render);
  driver_destroy_window(nwindow);

  return 0;
}