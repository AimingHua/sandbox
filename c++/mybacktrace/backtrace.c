#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <execinfo.h>
#include <signal.h>

void dump(int sig)
{
    void *buff[30]={0};
    size_t size;
    char **strings=NULL;
    size_t i=0;
    size=backtrace(buff,30);
    fprintf(stdout, "obtained %zd stack frames\n", size);
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

void func()
{
    char *p = NULL;
    *p = 'a';
}
void funb()
{
    func();
}
void funa()
{
    funb();
}

int main()
{
   if(signal(SIGSEGV, dump)==SIG_ERR) {
       perror("can't catch SIGSEGV");
   }
   funa();
   return 0;
}
