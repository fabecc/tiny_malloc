
#include <stdio.h>
#include <stdlib.h>
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
	int count = 1;
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
			}
			else
			{
				// Write data in memory
				*data = count++;
			}
		}
		else if (line[0] == 'f')
		{
			// Free memory
			int *data = (int*)strtol(line + 1, NULL, 0);
			tm_free(data);
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
