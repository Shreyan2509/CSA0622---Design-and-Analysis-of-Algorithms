#include <stdio.h>
#include <string.h>

int bruteForceStringMatch(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);
    int i, j;
    int found = 0;

    printf("\nSearching for \"%s\"...\n\n", pattern);

    for(i = 0; i <= n - m; i++)
    {
        j = 0;

        while(j < m && text[i + j] == pattern[j])
        {
            j++;
        }

        if(j == m)
        {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
    }

    if(!found)
    {
        printf("Pattern not found in the text.\n");
    }

    return found;
}

int main()
{
    char text[1000];
    char pattern[100];

    printf("=========================================\n");
    printf("     BRUTE FORCE STRING MATCHING\n");
    printf("=========================================\n");

    printf("\nEnter the text:\n");
    fgets(text, sizeof(text), stdin);

    // Remove newline character
    text[strcspn(text, "\n")] = '\0';

    printf("\nEnter the keyword to search: ");
    fgets(pattern, sizeof(pattern), stdin);

    pattern[strcspn(pattern, "\n")] = '\0';

    bruteForceStringMatch(text, pattern);

    printf("\n-----------------------------------------\n");
    printf("Time Complexity:\n");
    printf("Best Case  : O(n)\n");
    printf("Worst Case : O(n*m)\n");
    printf("Space Complexity : O(1)\n");
    printf("-----------------------------------------\n");

    return 0;
}
