#ifndef __NODEARV_PRIV_H
#define __NODEARV_PRIV_H

#include "nodearv.h"

struct nodearv_t{
	void* info;
	/*vários outros dados*/
	struct nodearv_t* esquerda;
	struct nodearv_t* direita;
};

#endif
