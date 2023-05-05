#ifndef _sask_driver
#include <sask/types.h>

enum driver_result
{
  DRIVER_FAIL,
  DRIVER_OK
};

enum driver_event
{
  DRIVER_EVENT_KEYPRESS,
};

typedef union
{
  u32 value;
  struct
  {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
  };
} color_t;

/* Initializes Driver */
enum driver_result driver_init(void);

/* Gets driver error message */
const char *driver_error(void);

/* Deinitializes the driver */
void driver_quit(void);

/*
 * Creates a window using driver
 * @returns A native window, otherwise, returns NULL which is a error
 */
void *driver_create_window(const char *title, u32 x, u32 y, u32 width,
                           u32 height);

/*
 * Destroys (closes) the window.
 * @param window A native driver window.
 */
void driver_destroy_window(void *window);

/*
 * Creates a renderer
 * @param window A native window
 * @returns A native renderer context
 */
void *driver_create_renderer(void *window);

/*
 * Destroys a renderer
 * @param renderer A native renderer
 */
void driver_destroy_renderer(void *renderer);

/*
 * Clear a native rendererer with the drawing buffer
 * @param renderer A native renderer
 */
void driver_render_clear(void *renderer);

/*
 * Swap back buffers with front buffers, is this may also be considered "flushing"
 * @param renderer A native renderer
 */
void driver_render_present(void *renderer);

/*
 * Render a rect */
enum driver_result driver_render_rect(void *renderer, u32 x, u32 y, u32 width, u32 height);

/*
 * Set render color*/
void driver_render_set_color(void *renderer, color_t color);

/*
 * Sleep current thread by ms miliseconds.
 * @param ms Time to delay
 */
void driver_delay(u32 ms);

void driver_render_copy(void *renderer);

void driver_event_next(void *event);

#define _sask_driver
#endif