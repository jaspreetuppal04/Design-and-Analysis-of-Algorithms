//assembly line

#include <stdio.h>

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    int n;

    printf("Enter number of stations: ");
    scanf("%d", &n);

    int a1[n], a2[n];        
    int t1[n], t2[n];        
    int e1, e2;              
    int x1, x2;              

    printf("Enter entry times for line 1 and line 2: ");
    scanf("%d %d", &e1, &e2);

    printf("Enter exit times for line 1 and line 2: ");
    scanf("%d %d", &x1, &x2);

    printf("Enter processing times for line 1:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a1[i]);

    printf("Enter processing times for line 2:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a2[i]);

    printf("Enter transfer times from line 1 to line 2:\n");
    for (int i = 1; i < n; i++)
        scanf("%d", &t1[i]);

    printf("Enter transfer times from line 2 to line 1:\n");
    for (int i = 1; i < n; i++)
        scanf("%d", &t2[i]);

    int f1[n], f2[n];

    // Base case
    f1[0] = e1 + a1[0];
    f2[0] = e2 + a2[0];

    // DP calculation
    for (int i = 1; i < n; i++)
    {
        f1[i] = min(f1[i-1] + a1[i],
                    f2[i-1] + t2[i] + a1[i]);

        f2[i] = min(f2[i-1] + a2[i],
                    f1[i-1] + t1[i] + a2[i]);
    }

    int result = min(f1[n-1] + x1,
                     f2[n-1] + x2);

    printf("Minimum time to manufacture product: %d\n", result);

    return 0;
}