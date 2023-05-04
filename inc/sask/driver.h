#ifndef _DRIVER_H
enum driver_init_result {
  FAIL,
  OK  
};

/* Initializes Driver */

enum driver_init_result driver_init(void);

#define _DRIVER_H
#endif