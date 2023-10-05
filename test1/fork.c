#include <stdio.h>

int main(void)
{
	pid_t = fork();
	if (pid < 0)
	{
		perror("fork failed");
		return 1;
	}
	else if (pid == 0)
	{
		printf("processid (PID=%d) is running.\n", getpid());
	}
	else
	{
		printf("parent process (PID=%d) is running, child pid=%d,\n");
	}
	return 0;
}
