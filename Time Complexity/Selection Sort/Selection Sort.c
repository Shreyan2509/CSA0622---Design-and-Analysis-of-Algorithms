#include <stdio.h>

int main()
{
    int n, i, j, minIndex, temp;

    printf("=====================================\n");
    printf("        SELECTION SORT\n");
    printf("=====================================\n");

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    printf("\nSorted Array:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    printf("\nTime Complexity : O(n^2)");
    printf("\nSpace Complexity: O(1)\n");

    return 0;
}
