#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <execinfo.h>
#include <signal.h>

/*dump function call stack frame when receive sigsegv signal*/
void dump(int sig)
{
    void *buff[30]={0};
    size_t size;
    char **strings=NULL;
    size_t i=0;

    /*30 is max stack frame size, size is actual frame size*/
    size=backtrace(buff,30);
    fprintf(stdout, "obtained %zd stack frames\n", size);
    //printf("obtained %zd stack frames\n", size);
    strings=backtrace_symbols(buff,size);
    if(strings==NULL) {
        perror("back_symbols");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<size; i++) {
        fprintf(stdout, "%s\n", strings[i]);
    }
    free(strings);
    strings=NULL;
    exit(0);
}
void fun_c()
{
    char *p = NULL;
    *p = 'a';
}
void fun_b()
{
    fun_c();
}
void fun_a()
{
    fun_b();
}

int main()
{
   //handle signal segment violation
   if(signal(SIGSEGV, dump)==SIG_ERR) {
       perror("can't catch SIGSEGV");
   }
   //process will crash when call fun_a()
   fun_a();
   return 0;
}
