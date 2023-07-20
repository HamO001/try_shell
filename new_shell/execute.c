#include "main.h"

/**
 * executeCommand - executes a command
 * @command: command passed
 */
void executeCommand(char *command)
{
	pid_t pid;
	int status;

	if (_strcmp(command, "exit") == 0)
		exitShell();

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return;
	}
	else if (pid == 0)
	{
		char *args[4];
		int i = 0;
		/*int j = 0;*/

		args[0] = "/bin/sh";
		args[1] = "-c";
		args[2] = (char *)command;
		args[3] = NULL;

		while (args[i] != NULL)
		i++;
		
		/* for (j = 0; j < i; j++)
		{
			write(STDOUT_FILENO, args[j], _strlen(args[j]));
			write(STDOUT_FILENO, " ", 1);
		}*/
		
		write(STDOUT_FILENO, "", 1);

		execve(args[0], args, NULL);
		perror("execvp");
		exit(1);

		/*char *args[] = {"/bin/sh", "-c", "", NULL};
		strncpy(args[2], command, strlen(command) + 1);
		char *envp[] = { NULL };
		execve(args[0], args, envp);
		perror("execve");
		exit(1);*/
	}
	else
		waitpid(pid, &status, 0);
}
