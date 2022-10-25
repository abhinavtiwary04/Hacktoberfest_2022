//Code to implement linear search using c

#include <stdio.h>
 
int search(int arr[], int N, int x)
{
    int i;
    for (i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
 

int main(void)
{
    int y;
    printf("Enter the no. of elements: ");
    scanf("%d",&y);
    int arr[y];
    
    int i;
    
    if(y!=0)
        printf("Enter elements of the array - \n");

    for(i=0;i<y;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    
    int x;
    printf("Enter the no. to be searched in th array: ");
    scanf("%d",&x);
    int N = sizeof(arr) / sizeof(arr[0]);
 
 
 
    int result = search(arr, N, x);
    
    if (result == -1)
        printf("Element is not present in array");
        
    else 
        printf("Element is present at position %d", result+1);
        
    return 0;
}
