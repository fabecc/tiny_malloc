
#include <stdio.h>
#include "tm.h"

#define BLOCK_SIZE   4
#define MEM_SIZE     10 * (BLOCK_SIZE + 1)
char memory[MEM_SIZE];

int main(void)
{
	int res;

	// Init tiny malloc module
	res = tm_init(memory, MEM_SIZE, BLOCK_SIZE);
	if (res != 0)
		perror("Failed to init tyny malloc");

	// Print stats
	tm_stats();

	// Get memory
	void* data = tm_malloc();
	if (data == NULL)
		perror("Failed to get memory");
	printf("Get memory address %p", data);

	// Free memory
	tm_free(data);

	// Print stats
	tm_stats();

	return 0;
}
