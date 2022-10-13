// In selection sort we find the smallest element in each pass and swap it with the first element of the unsorted array.

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int *arr, int size)
{
    int i, j, minIndx, temp;
    for (i = 0; i < size - 1; i++)
    {
        minIndx = i;
        for (j = i + 1; j < size; j++)
        {

            if (arr[j] < arr[minIndx])
            {
                minIndx = j;
            }
            
        }
        swap(&arr[i],&arr[minIndx]);
        
    }
}

int main()
{
    int arr[] = {32, 12, 7, 21, 90}; // 7,12,32,21,90 -- 1
                                     // 7,12,32,21,90 -- 2
                                     // 7,12,21,32,90 -- 3
                                     // 7,12,21,32,90 -- 4  (Sorted Array)
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);
    selectionSort(arr, size);
    printf("The sorted array is: \n");
    printArray(arr, size);
    return 0;
}