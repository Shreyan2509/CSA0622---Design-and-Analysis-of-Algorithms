#include <stdio.h>
#include <string.h>

int main()
{
    char text[1000], pattern[100];
    int i, j;
    int n, m;
    int found = 0;

    printf("=========================================\n");
    printf("     BRUTE FORCE STRING MATCHING\n");
    printf("=========================================\n");

    printf("Enter the text:\n");
    fgets(text, sizeof(text), stdin);

    // Remove newline character
    text[strcspn(text, "\n")] = '\0';

    printf("\nEnter the pattern to search: ");
    fgets(pattern, sizeof(pattern), stdin);

    pattern[strcspn(pattern, "\n")] = '\0';

    n = strlen(text);
    m = strlen(pattern);

    printf("\nSearching...\n");

    for(i = 0; i <= n - m; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(text[i + j] != pattern[j])
                break;
        }

        if(j == m)
        {
            printf("\nPattern found at index %d", i);
            found = 1;
        }
    }

    if(found == 0)
    {
        printf("\nPattern not found.");
    }

    printf("\n\nTime Complexity:");
    printf("\nBest Case    : O(n)");
    printf("\nAverage Case : O(n * m)");
    printf("\nWorst Case   : O(n * m)");

    printf("\n\nSpace Complexity: O(1)\n");

    return 0;
}
