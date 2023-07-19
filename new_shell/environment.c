#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * myEnviron - print current environment
 * @envp: pointer to environment variable array
 */
void myEnviron(char **envp)
{
	char **env = envp;

	while (*env != NULL)
	{
		size_t len = strlen(*env);

		write(STDOUT_FILENO, *env, len);
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

