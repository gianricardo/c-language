#include "port_p.h"
#include "common.h"

port_p PortCreate(int type)
{
  port_p p = ALLOC_NEW(port_t);
  
  if(p)
  {
    p->type = type;
  }
  
  return p;
}

void PortDestroy(port_pp pp)
{
  DESTROY_PP(pp)
}

int PortGetOutput(port_p p, int a, int b)
{
  P_GUARD_V(0)
  
  switch(p->type)
  {
    case PORT_AND:
      return (a&b? 1 : 0);
      
    case PORT_OR:
      return (a|b? 1 : 0);
      
    case PORT_XOR:
      return (a^b? 1 : 0);
      
    case PORT_NOR:
      return (a|b? 0 : 1);
      
    case PORT_NOT:
      return (  a? 0 : 1);
      
    case PORT_NAND:
      return (a&b? 0 : 1);
    
    default: 
      return 0;
  }
}

int PortGetType(port_p p)
{
  P_GUARD_V(0);
  
  return p->type;
}

void PortSetType(port_p p, int type)
{
  P_GUARD;
  
  p->type = type;
}