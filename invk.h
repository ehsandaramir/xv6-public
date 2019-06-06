// #ifndef _invk_h
// #define _invk_h

#include "date.h"

struct invk {
  int pid;
  int syscall_id;
  struct rtcdate time;

  int int_params[2];
  int int_params_c;

  char *str_params[2];
  int str_params_c;

  char ptr_params[10];
  int ptr_params_c;
};

// #endif // _invk_h