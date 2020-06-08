
#include <stdio.h>
#include "tm.h"

int main(void)
{
	int res;

	// Init tiny malloc module
	res = tm_init();
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
