#include <unistd.h>
#include <stdio.h>

int main()
{
    char *argv[]={"/bin/ls", NULL};
    if(fork()==0) {
        printf("in child process:\n");
        execv(argv[0], argv);
        printf("i will never be called\n");
    }
    sleep(2);
    printf("execution continues in parent process\n");
}
