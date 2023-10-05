#include <stdio.h>
#include <unistd.h>

/**
 * main - entry point
 * @ppid prints parent process id
 * return: 0
 */
int main(void)
{
	pid_t parentpid = getppid();
	printf("%u\n", parentpid);
	return 0;
}
