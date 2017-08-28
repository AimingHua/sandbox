#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/*Handle singals from child process*/
void signal_handler(int sig)
{
    printf("in signal handler for signal %d\n", sig);
    /*wait() is the key to acknowledging the SIGCHLD*/
    wait(0);
}

int main()
{
    /*Assign a signal handler to SIGCHLD*/
    sigset(SIGCHLD, signal_handler);
    if(!fork()) {
        /*Child process exit immediately*/
        _exit(0);
    }
    /*Parent process waiting for 60 seconds*/
    printf("Enter parent process\n");
    sleep(60);
    printf("Exit parent process\n");
}
