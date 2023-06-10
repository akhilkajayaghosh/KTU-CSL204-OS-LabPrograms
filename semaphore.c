#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>
#include<pthread.h>
sem_t empty;
sem_t full;
int data,counter=0,buffer[5];
void *producer()
{
    sem_wait(&empty);
    while(1)
    {
        if(counter!=5)
        {
            printf("Enter the data\n");
            scanf("%d",&data);
            printf("Buffered value is %d\n",data);
            counter++;
            buffer[counter]=data;
        }
        else{
            printf("Buffer is full\n");
            break;
        }
    }
    sem_post(&full);
}
void *consumer()
{
    sem_wait(&full);
    printf("Consumed datas are\n");
    while(1)
    {
        if(counter!=0)
        {
            printf("%d\n",buffer[counter]);
            counter--;
        }
        else{
            printf("Buffer is empty");
            break;
        }
    }
    sem_post(&empty);
}
void main()
{
    pthread_t prid,conid;
    pthread_create(&prid,NULL,producer,NULL);
    pthread_create(&conid,NULL,consumer,NULL);
    sem_init(&full,1,0);
    sem_init(&empty,1,1);
    pthread_join(prid,NULL);
    pthread_join(conid,NULL);
}