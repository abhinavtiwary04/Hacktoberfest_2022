#include <stdio.h>
int max, min;
int a[10];
void maxMin(int i, int j)
{
    int maxTemp, minTemp, mid;
    if (i == j)
    {
        max = min = a[i];
    }
    else
    {
        if (i == j - 1)
        {
            if (a[i] < a[j])
            {
                max = a[j];
                min = a[i];
            }
            else
            {
                max = a[i];
                min = a[j];
            }
        }
        else
        {
            mid = (i + j) / 2;
            maxMin(i, mid);
            maxTemp = max;
            minTemp = min;
            maxMin(mid + 1, j);
            if (max < maxTemp)
                max = maxTemp;
            if (min > minTemp)
                min = minTemp;
        }
    }
}
int main()
{
    int i, n;
    printf("\nEnter size of the array : ");
    scanf("%d", &n);
    printf("Enter the elements of the array : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    max = a[0];
    min = a[0];
    maxMin(0, n-1);
    printf("Max element : %d\n", max);
    printf("Min element : %d\n", min);
    return 0;
}
