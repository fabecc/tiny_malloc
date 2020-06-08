
#include <stdio.h>
#include "tm.h"

void perr(char* msg)
{
	printf("Error: %s\n", msg);
}

int main(void)
{
	int res;

	// Init tiny malloc module
	res = tm_init();
	if (res != 0) {
		perr("Failed to init tyny malloc");
		return 1;
	}

	// Print stats
	tm_stats();

	// Get memory
	int* data = (int*)tm_malloc();
	if (data == NULL) {
		perr("Failed to get memory");
		return 1;
	}
	printf("Get memory address %p\n", (void*)data);

	// Try to write something in memory
	*data = 0xdeadbeaf;

	// Free memory
	tm_free(data);

	// Print stats
	tm_stats();

	return 0;
}
