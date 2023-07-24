#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * executeEnv - Prints the environment variables
 *
 * @env: The environment variables to print
 *
 * Return: void
 */
void executeEnv(char **env)
{
	int i;
	size_t length;

	for (i = 0; env[i] != NULL; i++)
	{
		length = strlen(env[i]);
		write(STDOUT_FILENO, env[i], length);
		write(STDOUT_FILENO, "\n", 1);
	}
}
