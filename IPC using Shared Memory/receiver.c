#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<string.h>
void main()
{
    void *shm;
    int shmid;
    shmid=shmget((key_t)1124,1024,0644|IPC_CREAT);
    printf("Shared memory id=%d\n",shmid);
    shm=shmat(shmid,NULL,0);
    printf("Address is%p\n",shm);
    printf("Entered Message=%s",(char*)shm);
}