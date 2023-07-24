#include "main.h"

void _changeDir(char *path)
{
	if (chdir(path) != 0)
	{
		perror("cd");
	}
}
