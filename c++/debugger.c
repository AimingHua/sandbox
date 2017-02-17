#include <stdio.h>
#include <signal.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void signal_handler(int sig)
{
    printf("Process %ld received signal %d\n", sig);
}

void do_debugger(void)
{
    int status = 0;
    pid_t child;
    printf("In debugger process %ld \n", (long)getpid());
    if(signal(SIGCHLD, signal_handler) == SIG_ERR)
    {
        perror("signal");
	exit(-1);
    }

    do {
           child = wait(&status);
	   printf("Debugger exited wait()\n");
	   if(WIFSTOPPED(status))
           {
	       printf("Child has stopped due to signal %d\n", WSTOPSIG(status));
	   }
	   if(WIFSIGNALED(status))
	   {
	       printf("Child %ld received signal %d\n", (long)child, WTERMSIG(status));
	   }
    }while(!WIFEXITED(status));
}

void do_debuggie(void)
{
    char *argv[] = {"/tmp", NULL};
    char *envp[] = {NULL};

    printf("In debuggie process %ld\n", (long)getpid());
    if(ptrace(PTRACE_TRACEME,0,NULL,NULL))
    {
	    perror("ptrace");
	    return;
    }
    execve("/bin/ls", argv,envp);
}

int main()
{
	pid_t child;
	//creating child process, it will execute do_debuggie().
	//parent process will continue to do_debugger().
	child = fork();
	if(child==0)
	    do_debuggie();
	else if (child > 0)
	    do_debugger();
	else
	{
		perror("fork");
		return -1;
	}
	return 0;
}
