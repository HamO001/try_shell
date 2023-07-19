#include "main.h"

/**
 * _strcmp - function to compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: comapared strings
 */

int _strcmp(const char *s1, const  char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
		return (0);
		}
	s1++;
	s2++;
	}
	return ((*s1 < *s2) ? -1 : 1);
}
