#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int temp[100];

    i = low;
    j = mid + 1;
    k = low;

    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        mergeSort(arr, low, mid);

        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[100], n, i;

    printf("=====================================\n");
    printf("           MERGE SORT\n");
    printf("=====================================\n");

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("\nSorted Array:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    printf("\nTime Complexity:");
    printf("\nBest Case    : O(n log n)");
    printf("\nAverage Case : O(n log n)");
    printf("\nWorst Case   : O(n log n)");

    printf("\n\nSpace Complexity: O(n)\n");

    return 0;
}
