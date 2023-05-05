#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_video.h>
#include <sask/driver.h>

#define SDL2DRV(expr) (!(expr) ? DRIVER_OK : DRIVER_FAIL)

enum driver_result driver_init()
{
  return SDL2DRV(SDL_Init(SDL_INIT_VIDEO));
}

void driver_quit() { SDL_Quit(); }

const char *driver_error(void) { return SDL_GetError(); }

void *driver_create_window(const char *title, u32 x, u32 y, u32 width,
                           u32 height)
{
  return SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_SHOWN);
}

void driver_destroy_window(void *window) { SDL_DestroyWindow(window); }

void *driver_create_renderer(void *window)
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

enum driver_result driver_render_rect(void *renderer, u32 x, u32 y, u32 width, u32 height)
{
  SDL_Rect rect = {x, y, width, height};
  return SDL2DRV(SDL_RenderDrawRect(renderer, &rect));
}

void driver_render_set_color(void *renderer, color_t color)
{
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void driver_delay(u32 ms)
{
  SDL_Delay(ms);
}