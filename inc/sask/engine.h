#ifndef _sask_engine
#include "sask/driver.h"
#include "sask/keyboard.h"

typedef enum sask_result
{
  SASK_OK = 1,

  /* A Error caused by driver*/
  SASK_EDRIVERERR = -1
} sask_result_m;

typedef struct sask_app
{
  void *h_window, *h_render;
  driver_buffer_t buffer;

  bool should_quit;
  char key_state[128];
} sask_app_t;

/*
 * Initializes the engine, this function should be called once.
 */
sask_result_m sask_init(void);

/*
 * Destroys the engine, this functions should be called once.
 */
void sask_destroy(void);

/*
 * Verify if a key is pressed
 * @returns 1 if is pressed, otherwise 0.
 */
bool sask_keyboard_pressed(sask_app_t *app, sask_key_m key);

/* App functions */

/*
 * Creates an application.
 * @param app A reference for the application
 * @param title The title of the application
 * @param x The x position of window
 * @param y The y position of window
 * @param width The width of window
 * @param height The height of window
 */
sask_result_m sask_app_create(sask_app_t *app, void *title, u32 x, u32 y,
                              u32 width, u32 height);

/*
 * Destroys a application, by closing it's windows and handles
 * @param app A reference for the application
 */
void sask_app_destroy(sask_app_t *app);

/*
 * Renderize the window and receive OS events
 * @param app A reference for the application
 * */
void sask_app_next(sask_app_t *app);

/*
 * Gets last engine error
 */
const char *sask_error(void);

#define _sask_engine
#endif
