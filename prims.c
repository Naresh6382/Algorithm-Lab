#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, e;
    int cost[MAX][MAX]; 
    int visited[MAX] = {0};
    int i, j, u, v, edges = 0;
    int min, mincost = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INT_MAX;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter edges in the format: u v w (u and v are vertices, w is weight)\n");
    for (i = 0; i < e; i++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        cost[x][y] = w;
        cost[y][x] = w; 
}
    visited[0] = 1; 

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        min = INT_MAX;
        u = v = -1;

        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("%d -- %d  Weight = %d\n", u, v, cost[u][v]);
            mincost += cost[u][v];
            visited[v] = 1;
            edges++;
        }
    }

    printf("\nTotal cost of MST = %d\n", mincost);

    return 0;
}

