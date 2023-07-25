#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"

#define BUFFER_SIZE 1024
#define PROMPT "$ "

/**
 * readCommand - Reads a command from stdin
 * @buffer: Buffer to store the command
 * @size: Size of the buffer
 * Return: Number of bytes read
 */
ssize_t readCommand(char *buffer, size_t size)
{
	ssize_t bytesRead;

	bytesRead = read(STDIN_FILENO, buffer, size);
	if (bytesRead > 0 && buffer[bytesRead - 1] == '\n')
		buffer[bytesRead - 1] = '\0';
	return (bytesRead);
}

/**
 * main - Main entry point
 * Return: Always 0
 */
int main(void)
{
	char command[BUFFER_SIZE];
	ssize_t bytesize;
	int _isInteractive = isatty(STDIN_FILENO);

	while (1)
	{
		if (_isInteractive)
			write(STDOUT_FILENO, PROMPT, sizeof(PROMPT) - 1);

		bytesize = readCommand(command, sizeof(command));
		if (bytesize <= 0)
			break;

		if (_strcmp(command, "exit") == 0 || _strcmp(command, "quit") == 0)
			break;

		if (_strcmp(command, "clear") == 0)
		{
			_clear();
			continue;
		}
		if (_strcmp(command, "env") == 0)
		{
			_myEnviron(environ);
			continue;
		}
		if (_strcmp(command, "cd") == 0)
		{
			char *path = strtok(NULL, "\n");

			if (path == NULL || _strcmp(path, ".") == 0)
				/*change to current dir*/
			{
				if (chdir(".") != 0)
				{
					perror("chdir");
				}
			}
			else
			{
				DIR *dir = opendir(path);
				/*change to specified dir*/
				if (dir == NULL)
				{
					perror("opendir");
				}
				else
				{
					if (chdir(path) != 0)
					{
						perror("chdir");
					}
					closedir(dir);
				}
			}
			/*char cwd[PATH_MAX];*/

			/*if (getcwd(cwd, PATH_MAX) != NULL)
				printf("Current working dir is %s\n", cwd);

			else
				perror("getcwd");*/


			/*_changeDir(".");*/
			continue;
		}
		/*if (_strcmp(command , "echo $PATH") == 0)
		{
			char *path = getenv("PATH");

			printf("%s\n", path);
		}*/


		_executecmd(command);
	}

	return (0);
}
