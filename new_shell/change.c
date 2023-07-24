#include "main.h"
/**
 * _changeDir - funtion to change directory
 * @path: path to directory
 * Return: nothing
 */
void _changeDir(char *path)
{
	if (chdir(path) != 0)
	{
		perror("cd");
	}
}
