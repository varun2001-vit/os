#include<stdio.h>
int main()
{
int i,j,seek=0,n, request[100];
int head; //loc of head
int temp,max; 
printf("enter position of head\t");
scanf("%d",&head);
printf("enter number of location\t");
scanf("%d",&n);
printf("enter elements of disk queue\n");
for(i=0;i<n;i++)
{
scanf("%d",&request[i]);
}
request[n]=head;
n=n+1;
for(i=0;i<n;i++) // sorting disk locations
{
for(j=i;j<n;j++)
{
if(request[i]>request[j])
{
temp=request[i];
request[i]=request[j];
request[j]=temp;
}
}

}
max=request[n-1];
seek=(head-0)+(max-0);//this is shortcut for caculation seek time because the head will go to extreme left (0)
//then move to extreme right that is max of the array
// thus formula is (head-0)+(max-0)
printf("\n%d",seek);
return 0;
}

