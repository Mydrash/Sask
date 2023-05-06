#include <sask/driver.h>
#include <sask/engine.h>
#include <stddef.h>
#include <stdlib.h>

sask_result_e sask_init(void)
{
  if (!driver_init())
  {
    return SASK_EDRIVERERR;
  }

  return SASK_OK;
}

sask_result_e sask_app_create(sask_app_t *app, void *title, u32 x, u32 y,
                              u32 width, u32 height)
{
  app->h_window = driver_window_create(title, x, y, width, height);

  if (!app->h_window)
  {
    return SASK_EDRIVERERR;
  }

  app->h_render = driver_render_create(app->h_window);

  if (!app->h_render)
  {
    return SASK_EDRIVERERR;
  }

  app->buffer = driver_render_create_buffer(app->h_render, width, height);

  return SASK_OK;
}

void sask_app_destroy(sask_app_t *app)
{
  driver_destroy_buffer(&app->buffer);
  driver_destroy_renderer(app->h_render);
  driver_destroy_window(app->h_window);
}

void sask_destroy()
{
  driver_quit();
}

const char *sask_error(void)
{
  return driver_error();
}
