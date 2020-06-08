
#include <stdlib.h>

#include "tm.h"

#define BLOCK_SIZE   4
#define MEM_SIZE     10 * (BLOCK_SIZE + 1)
char memory[MEM_SIZE];

// Init Tiny Malloc
int tm_init()
{
	return 0;
}

// Get Memory
void* tm_malloc(void)
{
	return NULL;
}

// Free previous given memory block
void tm_free(void* data)
{
}

// Print stat on memory usage
void tm_stats(void)
{
}
