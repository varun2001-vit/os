#include<stdio.h>
int main()
{
int reference_string[50],frame[10],size,counter=0,faults=0;
int i=0,j=0,n,k=0;
printf("\nEnter Length of reference string:\n");//input the size of ref string
scanf("%d",&n);
printf("\nEnter Page reference string:\n");//input the page values
for(i=0;i<n;i++)
{
scanf("%d",&reference_string[i]);
}
printf("\n Enter Size of frame :");//frame size
scanf("%d",&size);
for(i=0;i<size;i++)
    {
      frame[i]= -1;//assigning null to the frame
	}
			
for(i=0;i<n;i++)
    {
        counter=0;// counter to check if page is alreaady present or not
        for(k=0;k<size;k++)
            {
			if(frame[k]==reference_string[i])
                counter=1;// if page is present
            }
        if (counter==0)//if page is not present bring and increment the faults
            {
                frame[j]=reference_string[i];//replace
                j=(j+1)%size;// so that j is between 0 and size -1 
                faults++;
            }
                                   
    }
printf("Page Faults:%d",faults);//no of faults
return 0;
}

