
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

	// User loop
	char line[1024];
	while (1)
	{
		// Print stats
		tm_stats();

		printf("\n");
		printf("What do you want to do [m/f<id>/q] ?\n");

		fgets(line, 1024, stdin);
		if (line[0] == 'm')
		{
			// Get memory
			int* data = (int*)tm_malloc();
			if (data == NULL) {
				perr("Failed to get memory");
				return 1;
			}
			printf("Get memory address %p\n", (void*)data);
			// Try to write something in memory
			*data = 0xdeadbeaf;
		}
		else if (line[0] == 'f')
		{
			// Free memory
//			tm_free(data);
		}
		else if (line[0] == 'q')
		{
			break ;
		}
		else
		{
			perr("Unknown action");
		}
	}

	return 0;
}
