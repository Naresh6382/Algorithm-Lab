#include <stdio.h>
#define MAX 10
#define INF 9999
int n, cost[MAX][MAX];
int visited[MAX];
int minCost = INF;
int startCity;
int bestPath[MAX], currentPath[MAX];
// Recursive function to find minimum cost path
void tsp(int city, int count, int currentCost) {
currentPath[count - 1] = city;
if (count == n && cost[city][startCity] > 0) {
int totalCost = currentCost + cost[city][startCity];
if (totalCost < minCost) {
minCost = totalCost;
for (int i = 0; i < n; i++)
bestPath[i] = currentPath[i];
bestPath[n] = startCity; // to complete the cycle
}
return;
}
for (int nextCity = 0; nextCity < n; nextCity++) {
if (!visited[nextCity] && cost[city][nextCity] > 0) {
visited[nextCity] = 1;
tsp(nextCity, count + 1, currentCost + cost[city][nextCity]);
visited[nextCity] = 0; // backtrack
}
}
}
int main() {
printf("Enter the number of cities: ");
scanf("%d", &n);
printf("Enter the cost matrix (%d x %d):\n", n, n);
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
scanf("%d", &cost[i][j]);
}
}
printf("Enter the starting city (0 to %d): ", n - 1);
scanf("%d", &startCity);
for (int i = 0; i < n; i++)
visited[i] = 0;
visited[startCity] = 1;
tsp(startCity, 1, 0);
printf("\nMinimum cost of travelling all cities = %d\n", minCost);
printf("Optimal Path: ");
for (int i = 0; i <= n; i++) {
printf("%d ", bestPath[i]);
if (i < n) printf("-> ");
}
printf("\n");
return 0;
}
