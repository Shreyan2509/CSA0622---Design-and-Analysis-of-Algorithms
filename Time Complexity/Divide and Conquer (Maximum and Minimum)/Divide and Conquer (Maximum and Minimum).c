#include <stdio.h>

int max, min;

void maxMin(int arr[], int low, int high)
{
    int mid;
    int max1, min1;

    if(low == high)
    {
        max = min = arr[low];
    }
    else if(low == high - 1)
    {
        if(arr[low] > arr[high])
        {
            max = arr[low];
            min = arr[high];
        }
        else
        {
            max = arr[high];
            min = arr[low];
        }
    }
    else
    {
        mid = (low + high) / 2;

        maxMin(arr, low, mid);
        max1 = max;
        min1 = min;

        maxMin(arr, mid + 1, high);

        if(max < max1)
            max = max1;

        if(min > min1)
            min = min1;
    }
}

int main()
{
    int arr[100];
    int n, i;

    printf("=====================================\n");
    printf(" DIVIDE AND CONQUER (MAX & MIN)\n");
    printf("=====================================\n");

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter %d elements:\n",n);

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    maxMin(arr,0,n-1);

    printf("\nMaximum Element = %d",max);
    printf("\nMinimum Element = %d",min);

    printf("\n\nTime Complexity:");
    printf("\nBest Case    : O(n)");
    printf("\nAverage Case : O(n)");
    printf("\nWorst Case   : O(n)");

    printf("\n\nSpace Complexity : O(log n)\n");

    return 0;
}
