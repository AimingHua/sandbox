#include <stdio.h>
#include <unistd.h>

int main()
{
    int i;
    if(fork()) {
        /*parent*/
        sleep(2);
        _exit(0);
    }
    for(int i=0; i<5; i++) {
        printf("my parent is %d\n", getppid());
        sleep(1);
    }
}
