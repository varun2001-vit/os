#include <stdio.h>
#include <pthread.h>

void* function(void *s);//function
int flag[2];
int turn,count=0,mode=0;
const int MAX = 1e9;
void lock_init()//declaring flag as 0
{
    flag[0] = flag[1] = 0;
    turn = 0;
}

void lock(int current)
{
    flag[current] = 1;

    turn = 1-current;
    while (flag[1-current]==1 && turn==1-current) ;//giving previous process the turn
}

void unlock(int current)
{
    flag[current] = 0;//breaking while
}

void* function(void *s)
{
    int i = 0;
    int current = (int*) s;
    printf("Process : %d\n", current);

    if(mode == 1)//mode 1 refers to with lock
        lock(current);
    for (i=0; i<MAX; i++)
        count++;

    if(mode == 1)//later after counting unlock
        unlock(current);
}

void main()
{
   
    pthread_t p1,p2,p3,p4;// 4 threads 2 with lock 2 without lock

    printf("\nwithout Lock\n");

    pthread_create(&p1, NULL, function, (void*)1);//  initalizing and creating threads
    pthread_create(&p2, NULL, function, (void*)2);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("Actual Count: %d | Expected Count: %d\n",count, MAX*2);//count is the count value from the above and max is 2* 1 epower9

    printf("\n\n with Lock\n");// with lock
    count = 0;//start agin
    mode = 1;//lock
    lock_init();

    pthread_create(&p3, NULL, function, (void*)3);
    pthread_create(&p4, NULL, function, (void*)4);

    pthread_join(p3, NULL);
    pthread_join(p4, NULL);

    printf("Actual Count: %d | Expected Count: %d\n",count, MAX*2);

}


