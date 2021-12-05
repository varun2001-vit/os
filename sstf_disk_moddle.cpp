#include<stdio.h>
#include<stdlib.h>
int main()
{
    int request[50],i,n,seek=0,head;
	int num=0;
    printf("Enter initial head position\n");//input
    scanf("%d",&head);
    
    printf("Enter the number of Requests\n");//input
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");//input
    for(i=0;i<n;i++)
     scanf("%d",&request[i]);
    
    
    
    
    
    while(num!=n)
    {
        int min=10000,diff,index;
        for(i=0;i<n;i++)
        {
           diff=abs(request[i]-head);//finding the minimum difference among all the track numbers
           if(min>diff)
           {
               min=diff;
               index=i;//taking the index
           }
           
        }
        seek=seek+min;//adding the seek
        head=request[index];//assigning head to new
        
        request[index]=10000;
        num++;
    }
    
    printf("%d",seek);
    return 0;
}
