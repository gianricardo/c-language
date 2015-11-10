#ifndef PORT_H
#define PORT_H

typedef struct port_t *port_p, **port_pp;

#define PORT_UNDEF 	0
#define PORT_AND 	1
#define PORT_OR 	2
#define PORT_XOR 	3
#define PORT_NOR 	4
#define PORT_NOT 	5
#define PORT_NAND 	6

port_p PortCreate(int type);
void PortDestroy(port_pp);

int PortGetOutput(port_p, int, int);

int PortGetType(port_p);
void PortSetType(port_p, int);

#endif