#include <stddef.h>

#include "sask/driver.h"
#include "sask/engine.h"
#include "sask/keyboard.h"

void sask_app_next(sask_app_t *app)
{
  struct driver_event event = driver_poll_event();
  size_t idx;

  switch (event.type)
  {
    case DRIVER_EVENT_KEYCHANGED:
      app->key_state[event.data.key.code] = event.data.key.pressed;
      break;
    case DRIVER_EVENT_QUIT_REQUESTED:
      app->should_quit = true;
      break;
  }

  driver_render_clear(app->h_render);
  driver_render_buffer(app->h_render, &app->buffer);
  driver_render_present(app->h_render);

  for (idx = 0; idx < (app->buffer.width * app->buffer.height); ++idx)
  {
    app->buffer.pixels[idx] = (color_m)(u32)0x00000000;
  }
}

bool sask_keyboard_pressed(sask_app_t *app, sask_key_m key)
{
  return app->key_state[key];
}
