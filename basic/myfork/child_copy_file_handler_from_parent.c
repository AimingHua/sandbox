/*
one process reads from the file, and the file pointer is moved for both processes. 
Likewise, when a file is written to, the next character goes to the end of the file. 
This makes sense, because the kernel keeps track of the open file's information. 
The file descriptor is merely an identifier for the process
*/
/*
standard output (the screen) is a file descriptor, too. 
This is duplicated during the fork, which is why both processes can write to the screen
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int fd_in, fd_out;
    char buf[1024];
    fd_in = open("infile", O_RDONLY);
    fd_out = open("outfile", O_WRONLY);
    fork();
    //following code will be executed both in parent and child process
    //if don't call execv to load image, two processes will execute same code
    while(read(fd_in, buf, 2)>0)
    {
        printf("%d: %s\n", getpid(), buf);
        sprintf(buf, "%d hello world\r\n", getpid());
        write(fd_out, buf, strlen(buf));
        sleep(1);
        memset(buf, 0, 1024);
    }
    sleep(10);
}
