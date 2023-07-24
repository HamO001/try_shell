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
	ssize_t bytesRead;
	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
			write(STDOUT_FILENO, PROMPT, sizeof(PROMPT) - 1);

		bytesRead = readCommand(command, sizeof(command));
		if (bytesRead <= 0)
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
			extern char **environ;

			_myEnviron(environ);
			continue;
		}
		if (_strcmp(command, "cd") == 0)
		{
			char *path = strtok(NULL, "\n");
			_changeDir(path);
			continue;
		}


		executeCommand(command);
	}

	return (0);
}
