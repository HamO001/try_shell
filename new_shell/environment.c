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
	char **env = envp;

	while (*env != NULL)
	{
		/*size_t len = strlen(*env);*/

		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

