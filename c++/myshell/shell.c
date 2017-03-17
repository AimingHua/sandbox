#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_LEN 1024

int main()
{
    char line[BUFFER_LEN];
    char *argv[100];
    char *path="/bin/";
    char progpath[20]={0};
    int argc;

    while(1) {
        //print prompt
        printf("my shell>> ");
        //get user input
        if(!fgets(line, BUFFER_LEN, stdin)) {
            break;
        }
        if(strcmp(line, "exit\n")==0) {
            break;
        }
        //seperate input using white space 
        char *token;
        token = strtok(line, " ");
        int i=0;
        while(token!=NULL) {
            argv[i]=token;
            token=strtok(NULL," ");
            i++;
        }
        argv[i]=NULL;
        argc=i;
        //print input command
        for(i=0; i<argc; i++) {
            printf("%s ", argv[i]);
        }
        strcpy(progpath, path); //progpath="/bin/"
        strcat(progpath, argv[0]); //progpath="/bin/ls"
        for(i=0; i<strlen(progpath); i++) { //delete new line
            if(progpath[i]=='\n') 
                progpath[i]='\0';
        }

        //fork a child process to execute the command
        int pid=fork();
        if(pid==0) { //child process
            printf("progpath=%s\r\n", progpath);
            execvp(progpath, argv);
            fprintf(stderr, "child process could not execvp\n");
        } else {  //parent process
            wait(NULL);
            printf("child exited\n");
        } 
    }
}
