#include<stdio.h>
int f(int time[], int size){// function to find the postion to be removed in lru
int i, min = time[0], pos = 0;
for(i = 1; i < size; ++i){
if(time[i] < min){
min = time[i];//finding the minimum time that a page was referenced last
pos = i;
}
}
return pos;//returning the pos
}
 
int main()
{
int no, n, frames[10], pages[30], counter = 0, time[10];//counter is for keeping track of time
int  c1=0, c2=0, i, j, pos, count = 0;//c1 and c2 are the flags count calculates the fault
printf("Enter lenght of reference string: ");
scanf("%d", &n);//input
printf("Enter reference string: ");
    for(i = 0; i < n; ++i){
     scanf("%d", &pages[i]);
    }
printf("Enter number of frames: ");//input frame size
scanf("%d", &no);
    
for(i = 0; i < no; ++i){
     frames[i] = -1;//assigning null
    }
    
    for(i = 0; i < n; ++i)
	{
     c1 = c2 = 0;//initally flag is zero
    
     for(j = 0; j < no; ++j)
	 {
     if(frames[j] == pages[i])
	 {//if page is already present
     counter++;//increamet the time for the frame to make it most recently accessed
     time[j] = counter;//storing
   c1 = c2 = 1;//change flag
   break;
     }
     }
    
     if(c1 == 0){//if the page is not present
for(j = 0; j < no; ++j){
     if(frames[j] == -1){//initial
     counter++;//increment time faults
     count++;
     frames[j] = pages[i];//replace
     time[j] = counter;
     c2 = 1;// to check if the pointer has not reached last frame
     break;
     }
     }
     }
    
     if(c2 == 0){//if page full replace
     pos = f(time, no);//find the pos
     counter++;//increment
     count++;
     frames[pos] = pages[i];
     time[pos] = counter;
     }
    }
printf("\nPage Faults :%d", count);//print
    
    return 0;
}
