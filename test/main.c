#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
char command[20];
char shell_version[10];

printf("Enter the shell version (0, 1, or 3): ");
fgets(shell_version, sizeof(shell_version), stdin);
shell_version[strcspn(shell_version, "\n")] = '\0';

snprintf(command, sizeof(command), "./shell%d", atoi(shell_version));
system(command);

return (0);
}
