#include <stdio.h>
#include <stdlib.h>

//system(const char *command): execute a shell command specified by command 
//system() library function use fork() to create child process that executes the shell command specified in command 
//and use execl to load program file, execl("/bin/sh", "sh", "-c", command, (char *) 0);
int main()
{
     printf("system('exit 0') return %d\r\n", system("exit 0"));
     printf("system('exit 2') return %d\r\n", system("exit 2"));
     printf("WEXITSTATUS(system('exit 0')) return %d\r\n", WEXITSTATUS(system("exit 0")));
     printf("WEXITSTATUS(system('exit 2')) return %d\r\n", WEXITSTATUS(system("exit 2")));
}
