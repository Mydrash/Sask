#include <stdio.h>

#include "sask/engine.h"

/* Experimental, this example is for testing */

int main(void)
{
  if (sask_init() != SASK_OK)
  {
    printf("Unable to initialize engine: %s", sask_error());
    return 1;
  }

  sask_app_t app;

  if (!sask_app_create(&app, "Sask App: Hello", 0, 0, 800, 420))
  {
    printf("Unable to create application: %s\n", sask_error());
    sask_destroy();
    return 1;
  }

  sask_app_destroy(&app);
  sask_destroy();
  return 0;
}
