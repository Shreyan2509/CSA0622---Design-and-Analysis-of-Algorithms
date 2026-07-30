#include <stdio.h>

int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            return mid;
        }
        else if(key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int n, i, key, result;
    int arr[100];

    printf("=====================================\n");
    printf("          BINARY SEARCH\n");
    printf("=====================================\n");

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("\nEnter %d elements in sorted order:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, n, key);

    if(result != -1)
    {
        printf("\nElement %d found at index %d.", key, result);
    }
    else
    {
        printf("\nElement %d not found.", key);
    }

    printf("\n\nTime Complexity:");
    printf("\nBest Case    : O(1)");
    printf("\nAverage Case : O(log n)");
    printf("\nWorst Case   : O(log n)");

    printf("\n\nSpace Complexity: O(1)\n");

    return 0;
}
