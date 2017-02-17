#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	pid = fork();
	
	if(pid==-1)
		exit(EXIT_FAILURE);
	if(pid==0)
		sleep(1);
		printf("this is child process and child pid=%d, parent pid=%d\r\n", getpid(), getppid());
	if(pid>0)
		printf("this is parent process and pid=%d, child pird=%d\r\n", getpid(), pid);
}
