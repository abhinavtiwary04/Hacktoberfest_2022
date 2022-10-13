#include <stdio.h>

void insertionSort(int arr[], int size)  // insertion sort is by default adaptive in nature
{
    int i, j;
    for (i = 1; i < size; i++)
    {
        int key = arr[i];
        for (j = i - 1; j >= 0 && key < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key; // when the ith element is smallest in the subarray and 'j' becomes -1.
    }
}
int main()
{
    int arr[] = {10, 52, 23, 7, 16};  // Hardcoded values
    insertionSort(arr, sizeof(arr) / sizeof(int));
    printf("The sorted array is: \n");
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}