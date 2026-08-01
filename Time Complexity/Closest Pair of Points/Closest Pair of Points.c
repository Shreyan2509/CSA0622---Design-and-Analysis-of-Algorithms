#include <stdio.h>
#include <math.h>

struct Point
{
    int x;
    int y;
};

int main()
{
    struct Point p[100];
    int n;
    int i, j;
    double distance;
    double minDistance;
    int p1 = 0, p2 = 1;

    printf("=====================================\n");
    printf("  CLOSEST PAIR OF POINTS\n");
    printf("      (BRUTE FORCE)\n");
    printf("=====================================\n");

    printf("Enter number of points: ");
    scanf("%d",&n);

    printf("\nEnter coordinates (x y):\n");

    for(i=0;i<n;i++)
    {
        printf("Point %d: ",i+1);
        scanf("%d%d",&p[i].x,&p[i].y);
    }

    minDistance = sqrt(pow(p[0].x-p[1].x,2)+pow(p[0].y-p[1].y,2));

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            distance = sqrt(pow(p[i].x-p[j].x,2)+pow(p[i].y-p[j].y,2));

            if(distance < minDistance)
            {
                minDistance = distance;
                p1 = i;
                p2 = j;
            }
        }
    }

    printf("\nClosest Pair:\n");

    printf("(%d,%d) and (%d,%d)\n",
            p[p1].x,p[p1].y,
            p[p2].x,p[p2].y);

    printf("\nMinimum Distance = %.2lf",minDistance);

    printf("\n\nTime Complexity:");
    printf("\nBest Case    : O(n^2)");
    printf("\nAverage Case : O(n^2)");
    printf("\nWorst Case   : O(n^2)");

    printf("\n\nSpace Complexity : O(1)\n");

    return 0;
}
