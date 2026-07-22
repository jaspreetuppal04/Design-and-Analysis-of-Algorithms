#include <stdio.h>

#define MAX 10

// Edge structure
struct Edge {
    int u, v, w;
};

// Parent array for union-find
int parent[MAX];

// Find function
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union function
void unionSet(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    parent[rootB] = rootA;
}

// Bubble sort edges by weight
void sortEdges(struct Edge edges[], int e) {
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, e;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    struct Edge edges[MAX];

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Initialize parent
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges
    sortEdges(edges, e);

    int totalCost = 0;

    printf("Edges in MST:\n");

    for (int i = 0; i < e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        // Check for cycle
        if (find(u) != find(v)) {
            printf("%d - %d = %d\n", u, v, edges[i].w);
            totalCost += edges[i].w;
            unionSet(u, v);
        }
    }

    printf("Total cost = %d\n", totalCost);

    return 0;
}