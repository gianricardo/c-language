#ifndef BITADDER_P_H
#define BITADDER_P_H

#include "bitadder.h"
#include "port.h"

typedef struct bitadder_t {

  port_p haAand;
  port_p haAxor;
  
  port_p haBand;
  port_p haBxor;
  
  port_p outOR;
  
} bitadder_t;

#endif