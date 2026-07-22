#include <stdio.h>

#define MAX 20

int parent[MAX];

int find(int i) {
    while(parent[i])
        i = parent[i];
    return i;
}

int unionSet(int i, int j) {
    if(i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int n, i, j, a, b, u, v, ne = 1;
    int min, mincost = 0;
    int cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    while(ne < n) {
        min = 999;

        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(unionSet(u, v)) {
            printf("Edge %d: (%d %d) cost = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("Minimum cost = %d\n", mincost);

    return 0;
}