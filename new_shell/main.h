#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

void handlePath(char *cmd);
void print_error_message(const char *command);
int execute_command(char **args);
void executeCommand(const char *command);
void myEnviron(char **envp);
void exitShell(void);
int _strcmp(const char *s1, const char *s2);
int _strlen(char *str);

#endif /* MAIN_H */
