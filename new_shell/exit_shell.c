#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * exitShell - Exits the shell
 */
void exitShell(void)
{
const char message[] = "Exiting the shell...\n";
write(STDOUT_FILENO, message, sizeof(message) - 1);
/* Additional cleanup or exit logic if needed */
}
