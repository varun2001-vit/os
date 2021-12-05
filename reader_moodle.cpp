#include <pthread.h>//for pthread_t,pthread_join,pthread_create
#include <semaphore.h>//for sem_wait ,sem_post
#include <stdio.h>
sem_t wrt,mutex;
int value = 2;//content to be read and changed in the critical section
int num = 0;// no of readers
void *reader(void *r)
{   
    // Reader acquire the lock before modifying numreader
    sem_wait(&mutex);
    num++;//increments as reader comes
    if(num == 1) {
        sem_wait(&wrt); // If this is the first reader, then it will block the writer
    }
    sem_post(&mutex);// releases for more readers
    // Reading Section
    printf("Reader %d: read value as %d\n",*((int *)r),value);//reading

    // Reader acquire the lock before modifying numreader
    sem_wait(&mutex);
    num--;//reader leaves
    if(num == 0) {
        sem_post(&wrt); // If this is the last reader, it will allow the writer to enter.
    }
    sem_post(&mutex);//release the lock
}


void *writer(void *w)//writer function
{   
    sem_wait(&wrt);//ensures mutual exclusion and allows writer to enter if there is no reader
    value = value+2;//critical section
    printf("Writer %d changed value to %d\n",(*((int *)w)),value);
    sem_post(&wrt);//writer leaves

}
int main()
{   

    pthread_t r[10],w[5];//declaring 5 writers and 10 readers
   sem_init(&mutex,0,1);// initializing mutex and wait to 1
    sem_init(&wrt,0,1);

    int num[10] = {1,2,3,4,5,6,7,8,9,10}; // numbering the producer and consumer

    for(int i = 0; i < 10; i++) {
        pthread_create(&r[i], NULL, (void *)reader, (void *)&num[i]);//initalizing
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&w[i], NULL, (void *)writer, (void *)&num[i]);
    }

    for(int i = 0; i < 10; i++) {
        pthread_join(r[i], NULL);//creating
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(w[i], NULL);
    }

    

    return 0;//end
    
}
