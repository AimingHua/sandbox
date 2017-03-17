#include <stdio.h>
#include <signal.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
//#include <linux/user.h>
#include <sys/user.h>
#include <sys/reg.h>
#include <time.h>

void signal_handler(int sig)
{
    printf("process %ld received signal %d\n", (long)getpid(), sig);
}

void do_debugger(pid_t child)
{
    int status = 0;
    long data;
    long orig_data;
    unsigned long addr;
    struct user_regs_struct regs;
    
    printf("in debugger process %ld\n", (long)getpid());
    if(signal(SIGCHLD, signal_handler) == SIG_ERR) {
        perror("signal");
        exit(-1);
    }
    //waiting for child process to stop ...
    wait(&status);
    //placing breakpoint ...
    addr = 0x400516;
    data = ptrace(PTRACE_PEEKTEXT, child, (void *)addr, NULL);
    orig_data = data;
    data = (data & ~0xff) | 0xcc;
    ptrace(PTRACE_POKETEXT, child, (void *)addr, data); 
    //breakpoint is ready, telling child process to continue running ...
    ptrace(PTRACE_CONT, child, NULL, NULL);
    child = wait(&status);
    //restoring original data ...
    ptrace(PTRACE_POKETEXT, child, (void *)addr, orig_data);
    //change RIP register so that it will point to the right address ...
    memset(&regs, 0, sizeof(regs));
    ptrace(PTRACE_GETREGS, child, NULL, &regs);
    printf("RIP before resuming child is %llu\r\n", regs.rip);
    regs.rip = addr;
    ptrace(PTRACE_SETREGS, child, NULL, &regs);
    //debuggee is now ready to get resumed ... waiting 10 seconds
    printf("time before debugger falling asleep: %ld\n", (long)time(NULL));
    sleep(10);
    printf("time after debugger falling asleep:%ld. resuming debuggee ...\r\n", (long)time(NULL));
    ptrace(PTRACE_CONT, child, NULL, NULL);
    child = wait(&status);
    if(WIFSTOPPED(status))
        printf("debuggee stopped %d\n", WSTOPSIG(status));
    if(WIFEXITED(status))
        printf("debuggee exited \n");

    printf("debugger exiting ...\r\n");
}

void do_debuggee(void)
{
    char *argv[] = {NULL};
    char *envp[] = {NULL};
    printf("in debuggee process %ld\r\n", (long)getpid()); 
    if(ptrace(PTRACE_TRACEME, 0, NULL, NULL))
    {
        perror("ptrace");
        return;
    }
    execve("sleeper", argv, envp);
}

int main()
{
    pid_t child;

    //create child process, it will execute do_debuggee();
    //parent process will continue to do_debugger()
    child = fork();
    if(child==0)
        do_debuggee();
    else if(child>0)
        do_debugger(child);
    else {
        perror("fork");
        return -1;
    }
    return 0;
}
