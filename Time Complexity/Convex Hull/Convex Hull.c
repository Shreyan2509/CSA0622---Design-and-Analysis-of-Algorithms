#include <stdio.h>

struct Point
{
    int x;
    int y;
};

int main()
{
    struct Point p[100];
    int n;
    int i, j, k;
    int pos, neg;
    int value;

    printf("=====================================\n");
    printf("   CONVEX HULL (BRUTE FORCE)\n");
    printf("=====================================\n");

    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("\nEnter the coordinates (x y):\n");

    for(i = 0; i < n; i++)
    {
        printf("Point %d: ", i + 1);
        scanf("%d %d", &p[i].x, &p[i].y);
    }

    printf("\nEdges of the Convex Hull are:\n\n");

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            pos = 0;
            neg = 0;

            for(k = 0; k < n; k++)
            {
                if(k == i || k == j)
                    continue;

                value = (p[j].x - p[i].x) * (p[k].y - p[i].y)
                      - (p[j].y - p[i].y) * (p[k].x - p[i].x);

                if(value > 0)
                    pos++;

                if(value < 0)
                    neg++;
            }

            if(pos == 0 || neg == 0)
            {
                printf("(%d,%d) ---- (%d,%d)\n",
                       p[i].x, p[i].y,
                       p[j].x, p[j].y);
            }
        }
    }

    printf("\n-------------------------------------\n");
    printf("Time Complexity:\n");
    printf("Best Case    : O(n^3)\n");
    printf("Average Case : O(n^3)\n");
    printf("Worst Case   : O(n^3)\n");
    printf("Space Complexity : O(1)\n");

    return 0;
}
