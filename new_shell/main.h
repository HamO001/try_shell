#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024

void handlePath(char *cmd);
void print_error_message(const char *command);
int execute_command(char **args);
void _executecmd(char *command);
void _myEnviron(char **envp);
void exitShell(void);
int _strcmp(const char *s1, const char *s2);
int _strlen(char *str);
void _clear();
/*<<<<<<< HEAD*/
void _changeDir(char *path);
/*=======*/
extern char **environ;
void executeEnv(void);
/*>>>>>>> 3f71e445227d2c668ed8627c601a444c33d67c4b*/

#endif /* MAIN_H */
