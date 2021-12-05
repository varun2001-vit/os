#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
// Maximum items a producer can produce or a consumer can consume is 5
// Size of the buffer is 5
sem_t empty;//initialized to size
sem_t full;//initialized to 0
int in = 0;//for procuder
int out = 0;//for consumer
int buffer[5];


void *producer(void *p)
{   // produce an item
    int nextproduced;
    for(int i = 0; i < 5; i++) {
        nextproduced = rand()%10; // Produce an random item
        sem_wait(&empty);// wait when there are no empty slots
        buffer[in] = nextproduced;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)p),buffer[in],in);
        in = (in+1)%5;
        sem_post(&full);// Signal to consumer that buffer has some   data and they can consume now
    }
}
void *consumer(void *c)
{   //consume an item
    for(int i = 0; i < 5; i++) {
        sem_wait(&full);// wait when there are no empty slots
        int nextconsumed = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)c),nextconsumed, out);
        out = (out+1)%5;
        sem_post(&empty);// Signal to consumer that buffer has some   data and they can consume now
    }
}

int main()
{   

    pthread_t p[5],c[5];// create consumer and producer threads
    sem_init(&empty,0,5);//initialization
    sem_init(&full,0,0);

    int num[5] = {1,2,3,4,5}; // numbering the producer and consumer

    for(int i = 0; i < 5; i++) {
        pthread_create(&p[i], NULL, (void *)producer, (void *)&num[i]);//initalizing
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&c[i], NULL, (void *)consumer, (void *)&num[i]);//initializing
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(p[i], NULL);//creating
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(c[i], NULL);//creating
    }

    

    return 0;
    
}
