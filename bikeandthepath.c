#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve(int row, int col, int n, int maze[n][n],
           int visited[n][n], char *path, int pathLen,
           char **ans, int *count) {

    // Reached destination
    if (row == n - 1 && col == n - 1) {
        path[pathLen] = '\0';

        ans[*count] = malloc((pathLen + 1) * sizeof(char));
        strcpy(ans[*count], path);
        (*count)++;

        return;
    }

    // Directions: Down, Left, Right, Up
    int dr[] = {1, 0, 0, -1};
    int dc[] = {0, -1, 1, 0};
    char dir[] = {'D', 'L', 'R', 'U'};

    visited[row][col] = 1;

    for (int i = 0; i < 4; i++) {

        int newRow = row + dr[i];
        int newCol = col + dc[i];

        // Check if the new cell is valid
        if (newRow >= 0 && newRow < n &&
            newCol >= 0 && newCol < n &&
            maze[newRow][newCol] == 1 &&
            visited[newRow][newCol] == 0) {

            path[pathLen] = dir[i];

            solve(newRow, newCol, n, maze, visited,
                  path, pathLen + 1, ans, count);
        }
    }

    // Backtrack
    visited[row][col] = 0;
}

void ratInMaze(int n, int maze[n][n]) {

    // Start or destination blocked
    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
        printf("No path\n");
        return;
    }

    int visited[n][n];

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }

    // Maximum possible path length
    char path[n * n];
    
    // Store all answers
    char *ans[1000];

    int count = 0;

    solve(0, 0, n, maze, visited,
          path, 0, ans, &count);

    if (count == 0) {
        printf("No path\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("%s ", ans[i]);
            free(ans[i]);
        }
        printf("\n");
    }
}

int main() {

    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    ratInMaze(4, maze);

    return 0;
}