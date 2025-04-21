#include "main.h"

void print_buffer(char buffer[], int *buff_ind)
{
	int i;

	printf("\nbuffer=: %s\n", buffer);
	if (*buff_ind > 0)
	{
		for (i = 0; i < *buff_ind; i++)
			_putchar(buffer[i]);
	}
	*buff_ind = 0;
}
