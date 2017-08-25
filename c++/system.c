#include <stdio.h>
#include <stdlib.h>

int main()
{
     printf("system('exit 0') return %d\r\n", system("exit 0"));
     printf("system('exit 2') return %d\r\n", system("exit 2"));
     printf("WEXITSTATUS(system('exit 0')) return %d\r\n", WEXITSTATUS(system("exit 0")));
     printf("WEXITSTATUS(system('exit 2')) return %d\r\n", WEXITSTATUS(system("exit 2")));
}
