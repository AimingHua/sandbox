#include <stdio.h>
#include <unistd.h>

/*
child process die will notify parent process with SIGCHLD
*/

int main()
{
    if(fork()==0) {
       /*child process exit immediately, will notify parent process*/
        _exit(0);
    }
    /*parent process don't handle child process */
    sleep(30);
}

