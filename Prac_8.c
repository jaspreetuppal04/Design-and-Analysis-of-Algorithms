//matrix chain 

#include <stdio.h>
#include <limits.h>

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

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int arr[n+1];

    printf("Enter dimensions array (size %d):\n", n+1);
    for(int i = 0; i <= n; i++)
        scanf("%d", &arr[i]);

    int m[n+1][n+1];

    // Step 1: If only one matrix, cost is 0
    for(int i = 1; i <= n; i++)
        m[i][i] = 0;

    // Step 2: Chain length from 2 to n
    for(int L = 2; L <= n; L++)
    {
        for(int i = 1; i <= n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for(int k = i; k < j; k++)
            {
                int cost = m[i][k] + m[k+1][j] 
                           + arr[i-1] * arr[k] * arr[j];

                if(cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", m[1][n]);

    return 0;
}