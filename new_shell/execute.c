#include "main.h"

/**
 * executeCommand - executes a command
 * @command: command passed
 */
void executeCommand(char *command)
{
	pid_t pid;
	int status;
	char *envp[] = {NULL};
	char *args[4];

	if (_strcmp(command, "exit") == 0)
		exitShell();

	_myEnviron(envp);

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return;
	}
	else if (pid == 0)
	{
		args[0] = "/bin/sh";
		args[1] = "-c";
		args[2] = command;
		args[3] = NULL;

		execve(args[0], args, envp);
		perror("execve");
		exit(1);
	}
	else
		waitpid(pid, &status, 0);
}
