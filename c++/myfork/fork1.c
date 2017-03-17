#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    pid=fork();
    printf("pid=%d\n", pid);
}
