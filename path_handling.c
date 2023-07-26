#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <sys/wait.h>
#include "main.h"

/**
 * handlePath - create the path required and execute the command
 * @cmd: command passed
 */
void handlePath(char *cmd)
{
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *token = strtok(path_copy, ":");
    char cmmd[100] = "";
    int exists = 0;

    while (token != NULL)
    {
        size_t token_len = strlen(token);
        size_t cmd_len = strlen(cmd);
        if (token_len + cmd_len + 2 < sizeof(cmmd))
        {
            write(STDOUT_FILENO, token, token_len);
            write(STDOUT_FILENO, "/", 1);
            write(STDOUT_FILENO, cmd, cmd_len);

            if (access(cmmd, X_OK) == 0)
            {
                exists = 1;
                break;
            }
        }
        token = strtok(NULL, ":");
    }

    free(path_copy);

    if (!exists)
    {
        write(STDOUT_FILENO, "Command not found\n", strlen("Command not found\n"));
        return;
    }

    char *args[] = {cmmd, cmd, NULL};
    execve(cmmd, args, NULL);

    write(STDOUT_FILENO, "Command execution failed\n", strlen("Command execution failed\n"));
    exit(1);
}

