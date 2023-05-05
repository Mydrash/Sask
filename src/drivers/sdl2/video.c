#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_video.h>
#include <sask/driver.h>

#define SDL2DRV(expr) (!(expr) ? DRIVER_OK : DRIVER_FAIL)

enum driver_result driver_init()
{
  return SDL2DRV(SDL_Init(SDL_INIT_VIDEO));
}

const char *driver_error(void) { return SDL_GetError(); }

void *driver_window_create(const char *title, u32 x, u32 y, u32 width,
                           u32 height)
{
  return SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_SHOWN);
}

void *driver_renderer_create(void *window)
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

device_framebuffer_t driver_render_create_buffer(void *renderer, u32 width, u32 height)
{
  device_framebuffer_t fb = {width, height, width * sizeof(color_t)};
  fb.pixels = calloc(sizeof(color_t), width * height);
  fb.referer = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);
  return fb;
}

enum driver_result driver_render_buffer(void *renderer, device_framebuffer_t *fb)
{
  if (!(SDL2DRV(SDL_UpdateTexture(fb->referer, NULL, fb->pixels, fb->pitch))))
  {
    return DRIVER_FAIL;
  }

  return SDL2DRV(SDL_RenderCopy(renderer, fb->referer, NULL, NULL));
}

union driver_event driver_poll_event(void)
{
  SDL_Event sdl_event;
  SDL_PollEvent(&sdl_event);
  union driver_event event;

  switch (sdl_event.type)
  {
  case SDL_KEYDOWN:
    event.type = DRIVER_EVENT_KEYCHANGED;
    event.key.code = sdl_event.key.keysym.sym;
    event.key.pressed = true;

  case SDL_KEYUP:
    event.type = DRIVER_EVENT_KEYCHANGED;
    event.key.code = sdl_event.key.keysym.sym;
    event.key.pressed = false;

  case SDL_QUIT:
    event.type = DRIVER_EVENT_QUIT_REQUESTED;
    break;
  }

  return event;
}
void driver_destroy_buffer(device_framebuffer_t *fb)
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