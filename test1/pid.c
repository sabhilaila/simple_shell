#include <stdio.h>
#include <unistd.h>

/**
 * main - entry point
 *
 *
 * return: 0
 */
int main(void)
{
	pid_t processid = getpid();
	printf("%u\n", processid);
	return 0;
}
