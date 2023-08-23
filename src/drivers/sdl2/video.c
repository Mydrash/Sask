#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_video.h>

#include "sask/driver.h"
#include "sask/keyboard.h"
#define SDL2DRV(expr) (!(expr) ? DRIVER_OK : DRIVER_FAIL)

enum driver_result driver_init()
{
  return SDL2DRV(SDL_Init(SDL_INIT_VIDEO));
}

const char *driver_error(void)
{
  return SDL_GetError();
}

void *driver_window_create(const char *title, u32 x, u32 y, u32 width,
                           u32 height)
{
  return SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_SHOWN);
}

void *driver_render_create(void *window)
{
  return SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void driver_destroy_renderer(void *renderer)
{
  SDL_DestroyRenderer(renderer);
}

void driver_render_clear(void *renderer)
{
  SDL_RenderClear(renderer);
}

void driver_render_present(void *renderer)
{
  SDL_RenderPresent(renderer);
}

driver_buffer_t driver_render_create_buffer(void *renderer, u32 width,
                                            u32 height)
{
  driver_buffer_t fb = {width, height};
  fb.pixels = (color_m *)calloc(sizeof(color_m), width * height);
  fb.pitch = sizeof(color_m) * width;
  fb.referer = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                                 SDL_TEXTUREACCESS_STREAMING, width, height);
  return fb;
}

enum driver_result driver_render_buffer(void *renderer, driver_buffer_t *fb)
{
  if (!(SDL2DRV(SDL_UpdateTexture(fb->referer, NULL, fb->pixels, fb->pitch))))
  {
    return DRIVER_FAIL;
  }

  return SDL2DRV(SDL_RenderCopy(renderer, fb->referer, NULL, NULL));
}

struct driver_event driver_poll_event(void)
{
  SDL_Event sdl_event;
  SDL_PollEvent(&sdl_event);
  struct driver_event event = {0};

  switch (sdl_event.type)
  {
    case SDL_KEYDOWN:
      event.data.key.code = sdl_event.key.keysym.sym > __SASK_KEY_LAST
                                ? sdl_event.key.keysym.scancode
                                : sdl_event.key.keysym.sym;
      event.data.key.pressed = true;
      event.type = DRIVER_EVENT_KEYCHANGED;
      break;

    case SDL_KEYUP:
      event.data.key.code = sdl_event.key.keysym.sym > __SASK_KEY_LAST
                                ? sdl_event.key.keysym.scancode
                                : sdl_event.key.keysym.sym;
      event.data.key.pressed = false;
      event.type = DRIVER_EVENT_KEYCHANGED;
      break;

    case SDL_QUIT:
      event.type = DRIVER_EVENT_QUIT_REQUESTED;
      break;
  }

  return event;
}

void driver_destroy_buffer(driver_buffer_t *fb)
{
  SDL_DestroyTexture(fb->referer);
  free(fb->pixels);
}

void driver_destroy_window(void *window)
{
  SDL_DestroyWindow(window);
}

void driver_delay(u32 ms)
{
  SDL_Delay(ms);
}

void driver_quit()
{
  SDL_Quit();
}
