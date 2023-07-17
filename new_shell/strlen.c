#include "main.h"


int _strlen(char *str)
{
	size_t i;

	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}
