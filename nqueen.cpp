#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int board[MAX][MAX];

void printBoard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
}


bool isSafe(int row, int col, int n) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve the problem
bool solveNQUtil(int col, int n) {
    // If all queens are placed, return true
    if (col >= n)
        return true;

    // Try placing queen in all rows in this column
    for (int i = 0; i < n; i++) {
        if (isSafe(i, col, n)) {
            board[i][col] = 1;  // Place queen

            // Recur to place rest of queens
            if (solveNQUtil(col + 1, n))
                return true;

            // If placing queen here doesn't lead to a solution, backtrack
            board[i][col] = 0;
        }
    }

    // If queen can't be placed in any row in this column
    return false;
}

int main() {
    int n;

    printf("Enter the number of queens (N): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Please enter a value between 1 and %d.\n", MAX);
        return 1;
    }

    // Initialize board to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    if (solveNQUtil(0, n)) {
        printf("Solution for %d queens:\n", n);
        printBoard(n);
    } else {
        printf("No solution exists for %d queens.\n", n);
    }

    return 0;
}

