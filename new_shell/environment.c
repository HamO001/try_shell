#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _myEnviron - print current environment
 * @envp: pointer to environment variable array
 */
void _myEnviron(char **envp)
{
	int i = 0;

	while (envp[i])
	{
		int j = 0;

		while (envp[i][j])
		{
			j++;
		}
		write(1, envp[i], j);
		write(1, "\n", 1);
		i++;
	}
}

