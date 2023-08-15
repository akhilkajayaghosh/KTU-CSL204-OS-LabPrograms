#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
void main()
{
    int p,wstatus;
    p=fork();
    if(p==0)
    {
        sleep(5);
        printf("Child Process with pid=%d\n",getpid());
        exit(10);
    }
    else{
        wait(&wstatus);
        printf("Parent Process with pid=%d\n",getpid());
        printf("Exit status of child=%d\n",WEXITSTATUS(wstatus));
    }
}