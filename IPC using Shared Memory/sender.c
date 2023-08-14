#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<string.h>
void main()
{
    void *shm;
    int shmid;
    char buf[20];
    shmid=shmget((key_t)1124,1024,0644|IPC_CREAT);
    printf("Shared memory id=%d",shmid);
    shm=shmat(shmid,NULL,0);
    printf("Address is%p\n",shm);
    printf("Enter the message:\n");
    read(0,buf,20);
    strcpy(shm,buf);
    printf("Message=%s",(char*)shm);
}