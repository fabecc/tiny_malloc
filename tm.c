
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "tm.h"

// Configuration
#define BLOCK_SIZE        4
#define NUMBER_OF_BLOCK   10

// Internal
#define MEM_SIZE          (10 * (BLOCK_SIZE + 1))
#define REAL_BLOCK_SIZE   (BLOCK_SIZE + 1)

char memory[MEM_SIZE];


// Init Tiny Malloc
int tm_init()
{
	int nb_block = MEM_SIZE / REAL_BLOCK_SIZE;
	for (int i = 0; i < nb_block; ++i) {
		memory[i * REAL_BLOCK_SIZE] = 0;
		memset(memory + i * REAL_BLOCK_SIZE + 1, 0, BLOCK_SIZE);
	}
	return 0;
}

// Get Memory
void* tm_malloc(void)
{
	int nb_block = MEM_SIZE / REAL_BLOCK_SIZE;
	for (int i = 0; i < nb_block; ++i) {
		if (memory[i * REAL_BLOCK_SIZE] == 0)
		{
			memory[i * REAL_BLOCK_SIZE] = 1;
			return memory + i * REAL_BLOCK_SIZE + 1;
		}
	}
	return NULL;
}

// Free previous given memory block
void tm_free(void* data)
{
	printf("Free %p\n", data);
	char* ptr = ((char*)data) - 1;
	*ptr = 0;
}

// Print stat on memory usage
void tm_stats(void)
{
	printf(">>>>>>>>>>>>>>>>>\n");
	printf("  Block size: %d\n", BLOCK_SIZE);
	printf("  Number of block: %d\n", NUMBER_OF_BLOCK);
	int nb_block = MEM_SIZE / REAL_BLOCK_SIZE;
	for (int i = 0; i < nb_block; ++i) {
		if (memory[i * REAL_BLOCK_SIZE] == 0x01) {
			void* addr = memory + i * REAL_BLOCK_SIZE + 1;
			int value = *(int*)addr;
			printf("  Block-%d is used (%p), value is 0x%x\n", i, addr, value);
		}
		else {
			printf("  Block-%d is free\n", i);
		}
	}
	printf("<<<<<<<<<<<<<<<<\n");
}
