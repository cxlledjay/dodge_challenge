#include "game_include/random.h"

// ---------------------------------------------------------------------------
// set seeds

void rng_init(rng_t* p, unsigned int seed0, unsigned int seed1, unsigned int seed2, unsigned int seed3)
{
	p->a = seed0;
	p->b = seed1;
	p->c = seed2;
	p->x = seed3;
}

// ---------------------------------------------------------------------------
// 8-bit random number (full 2^32 period and full range of values 0 - 255)

unsigned int rand(rng_t* p)
{
	p->x++;               					//x is incremented every round and is not affected by any other variable
	p->a = (p->a ^ p->c ^ p->x);       		//note the mix of addition and XOR
	p->b = (p->b + p->a);         			//and the use of very few instructions
	p->c = ((p->c + (p->b >> 1)) ^ p->a);	//the right shift is to ensure that high-order bits from b can affect  
	return p->c;          					//low order bits of other variables
}

// ****************************************************************************************
// end of file
// ****************************************************************************************
