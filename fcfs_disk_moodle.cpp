#include<stdio.h>
#include<stdlib.h>
int main()
{
    int request[40],i,n,seek=0,head;
    printf("Enter initial head position\n");//initial head 
    scanf("%d",&head);
    printf("Enter the number of Requests\n");//no
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");//input track request 
    for(i=0;i<n;i++)
     scanf("%d",&request[i]);
    
    
    //  FCFS disk scheduling
    
    for(i=0;i<n;i++)
    {
        seek=seek+abs(request[i]-head);//just subtract consescutive requests and add to seek time
        head=request[i];
    }
    printf("\n");
    
    printf("%d",seek);
    return 0;
    
}
