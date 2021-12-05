#include<stdio.h>
int main()
{
    int no, n, frames[10], pages[30], temp[10];
	int  c1, c2, c3,pos, max, faults = 0;
	int  i, j, k;
    printf("Enter  size of page reference: ");
    scanf("%d", &n);
    
    printf("Enter page reference string: ");//input
    
    for(i = 0; i < n; ++i){
        scanf("%d", &pages[i]);
    }
    printf("Enter size of frame: ");//input
    scanf("%d", &no);
    
    for(i = 0; i < no; ++i){
        frames[i] = -1;//assisgning null
    }
    
    for(i = 0; i < n; ++i){
        c1 = c2 = 0;//initially zero
        
        for(j = 0; j < no; ++j){
            if(frames[j] == pages[i]){
                   c1 = c2 = 1;//if present do nothing
                   break;
               }
        } 
        
        if(c1 == 0){//if not present
            for(j = 0; j < no; ++j){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = pages[i];//assigning and incrementing faults
                    c2 = 1;
                    break;
                }
            }    
        }
        
        if(c2 == 0){//if pointer reached size-1
         c3 =0;
        
            for(j = 0; j < no; ++j){
             temp[j] = -1;//temp array
             for(k = i + 1; k < n; ++k){//checking future elements
             if(frames[j] == pages[k]){
             temp[j] = k;//assigning the location to temp frame
             break;
             }
             }
            }
            
            for(j = 0; j < no; ++j){
             if(temp[j] == -1){
             pos = j;// eleemnt is not present in future
             c3 = 1;
             break;
             }
            }
            
            if(c3 ==0){
             max = temp[0];
             pos = 0;
            
             for(j = 1; j < no; ++j){
             if(temp[j] > max){
             max = temp[j];//calculating maximum futher element
             pos = j;
             }
             }            
            }
frames[pos] = pages[i];//replace
faults++;
        }
        
        
    }
    
    printf("\nPage Faults : %d", faults);
    
    return 0;
}
