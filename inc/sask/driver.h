#ifndef _sask_driver
#include <sask/types.h>

enum driver_result
{
  DRIVER_FAIL,
  DRIVER_OK
};

enum driver_event_type
{
  DRIVER_EVENT_QUIT_REQUESTED = 1,
  DRIVER_EVENT_KEYCHANGED
};

struct driver_event_key
{
  u32 code;
  bool pressed;
};

union driver_event_payload
{
  struct driver_event_key key;
};

struct driver_event
{
  enum driver_event_type type;
  union driver_event_payload data;
};

typedef union
{
  u32 value;
  struct
  {
    u8 b;
    u8 g;
    u8 r;
    u8 a;
  };
} color_t;

typedef struct
{
  u32 width, height, pitch;
  color_t *pixels;
  void *referer;
} device_framebuffer_t;

/* Initializes Driver */
enum driver_result driver_init(void);

/* Gets driver error message */
const char *driver_error(void);

/* Deinitializes the driver */
void driver_quit(void);

/**
 * Creates a window using driver
 * @returns A native window, otherwise, returns NULL which is a error
 */
void *driver_window_create(const char *title, u32 x, u32 y, u32 width,
                           u32 height);

/**
 * Destroys (closes) the window.
 * @param window A native driver window.
 */
void driver_destroy_window(void *window);

/**
 * Creates a renderer
 * @param window A native window
 * @returns A native renderer context
 */
void *driver_renderer_create(void *window);

/**
 * Destroys a renderer
 * @param renderer A native renderer
 */
void driver_destroy_renderer(void *renderer);

/**
 * Clear a native rendererer with the drawing buffer
 * @param renderer A native renderer
 */
void driver_render_clear(void *renderer);

/**
 * Swap back buffers with front buffers, is this may also be considered
 * "flushing"
 * @param renderer A native renderer
 */
void driver_render_present(void *renderer);

/**
 * Creates a framebuffer for device
 * @param renderer A native renderer
 * @param width A width for framebuffer
 * @param height A height for framebuffer
 */
device_framebuffer_t driver_render_create_buffer(void *renderer, u32 width,
                                                 u32 height);

/**
 * Destroys a framebuffer
 * @param fb The framebuffer
 */
void driver_destroy_buffer(device_framebuffer_t *fb);

/**
 * Update and render a framebuffer
 * @param renderer The native renderer
 * @param buffer The framebuffer
 */
enum driver_result driver_render_buffer(void *renderer,
                                        device_framebuffer_t *buffer);

/**
 * Polls a event
 */
struct driver_event driver_poll_event(void);

/**
 * Sleep current thread by ms miliseconds.
 * @param ms Time to delay
 */
void driver_delay(u32 ms);

#define _sask_driver
#endif
