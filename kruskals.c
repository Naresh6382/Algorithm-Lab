#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an edge
struct Edge {
    int u, v, w;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to find parent of a node (with path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to union two subsets
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges (for sorting)
int compare(const void* a, const void* b) {
    struct Edge* e1 = (struct Edge*)a;
    struct Edge* e2 = (struct Edge*)b;
    return e1->w - e2->w;
}

int main() {
    int n, e, i;
    struct Edge edges[MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter edges in the format: u v w (u and v are vertices, w is weight)\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Sort edges by weight
    qsort(edges, e, sizeof(edges[0]), compare);

    // Allocate memory for subsets
    struct Subset* subsets = (struct Subset*)malloc(n * sizeof(struct Subset));

    for (i = 0; i < n; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int mincost = 0;
    printf("\nEdges in the Minimum Spanning Tree:\n");

    int count = 0; // Number of edges in MST
    for (i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        int set_u = find(subsets, u);
        int set_v = find(subsets, v);

        if (set_u != set_v) {
            printf("%d -- %d  Weight = %d\n", u, v, edges[i].w);
            mincost += edges[i].w;
            Union(subsets, set_u, set_v);
            count++;
        }
    }

    printf("\nTotal cost of MST = %d\n", mincost);

    free(subsets);
    return 0;
}
