#pragma once

/**********************************************************************************
 * good 32-bit seed pseudo 8-bit rng (not mine, credit @Peer Johannsen)
 **********************************************************************************/



/***************************************************
 * data type
 ***************************************************/

typedef struct _rng_t
{
	unsigned int a;
	unsigned int b;
	unsigned int c;
	unsigned int x;
}rng_t;


/// @brief rng object for global use
extern rng_t random_obj;


/***************************************************
 * functions
 ***************************************************/

/**
 * @brief initialize rng object
 * @param p rng object
 * @param seed 32-bit seed (split into 4 bytes)
 */
void rng_init(rng_t* p, unsigned int seed0, unsigned int seed1, unsigned int seed2, unsigned int seed3);

/**
 * @brief generate next pseudo random number
 * @param p rng object
 * @returns 8-bit pseudo random number
 */
unsigned int rand(rng_t* p);
