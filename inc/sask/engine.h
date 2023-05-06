#ifndef _sask_engine
#include <sask/driver.h>

typedef enum sask_result
{
  SASK_OK = 1,

  /* A Error caused by driver*/
  SASK_EDRIVERERR = -1
} sask_result_e;

typedef struct sask_app
{
  void *h_window, *h_render;
  driver_buffer_t buffer;

  bool should_quit;
  char key_state[32];
} sask_app_t;

sask_result_e sask_init(void);
void sask_destroy(void);

bool sask_keyboard_pressed(sask_app_t *app, u32 key);
sask_result_e sask_app_create(sask_app_t *app, void *title, u32 x, u32 y,
                              u32 width, u32 height);
void sask_app_destroy(sask_app_t *app);
void sask_app_next(sask_app_t *app);

const char *sask_error(void);

#define _sask_engine
#endif
