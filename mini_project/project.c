#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 5
#define COL 5

// Structure for each cell
struct Node {
    int x, y;
    int g, h, f;
    int parentX, parentY;
};

// Check valid cell
int isValid(int x, int y) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL);
}

// Check destination
int isDestination(int x, int y, int destX, int destY) {
    return (x == destX && y == destY);
}

// Heuristic (Manhattan Distance)
int calculateH(int x, int y, int destX, int destY) {
    return abs(x - destX) + abs(y - destY);
}

// Print path
void printPath(struct Node grid[ROW][COL], int destX, int destY) {
    int x = destX, y = destY;

    printf("\nPath:\n");

    while (!(grid[x][y].parentX == x && grid[x][y].parentY == y)) {
        printf("(%d,%d) <- ", x, y);
        int tempX = grid[x][y].parentX;
        int tempY = grid[x][y].parentY;
        x = tempX;
        y = tempY;
    }
    printf("(%d,%d)\n", x, y);
}

// A* Algorithm
void aStar(int gridMap[ROW][COL], int startX, int startY, int destX, int destY) {

    struct Node grid[ROW][COL];

    // Initialize
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            grid[i][j].f = 9999;
            grid[i][j].g = 9999;
            grid[i][j].h = 9999;
            grid[i][j].parentX = -1;
            grid[i][j].parentY = -1;
        }
    }

    int x = startX, y = startY;
    grid[x][y].f = 0;
    grid[x][y].g = 0;
    grid[x][y].h = 0;
    grid[x][y].parentX = x;
    grid[x][y].parentY = y;

    int openList[ROW][COL] = {0};

    openList[x][y] = 1;

    while (1) {
        int minF = 9999, currX = -1, currY = -1;

        // Find node with lowest f
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (openList[i][j] && grid[i][j].f < minF) {
                    minF = grid[i][j].f;
                    currX = i;
                    currY = j;
                }
            }
        }

        if (currX == -1) {
            printf("No path found\n");
            return;
        }

        openList[currX][currY] = 0;

        // Destination reached
        if (isDestination(currX, currY, destX, destY)) {
            printPath(grid, destX, destY);
            return;
        }

        // 4 directions
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newX = currX + dx[i];
            int newY = currY + dy[i];

            if (isValid(newX, newY) && gridMap[newX][newY] == 0) {

                int gNew = grid[currX][currY].g + 1;
                int hNew = calculateH(newX, newY, destX, destY);
                int fNew = gNew + hNew;

                if (grid[newX][newY].f > fNew) {
                    openList[newX][newY] = 1;

                    grid[newX][newY].f = fNew;
                    grid[newX][newY].g = gNew;
                    grid[newX][newY].h = hNew;
                    grid[newX][newY].parentX = currX;
                    grid[newX][newY].parentY = currY;
                }
            }
        }
    }
}

int main() {

    int gridMap[ROW][COL];

    printf("Enter grid (0 = free, 1 = obstacle):\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            scanf("%d", &gridMap[i][j]);
        }
    }

    int startX, startY, destX, destY;

    printf("Enter start position (x y): ");
    scanf("%d %d", &startX, &startY);

    printf("Enter destination position (x y): ");
    scanf("%d %d", &destX, &destY);

    aStar(gridMap, startX, startY, destX, destY);

    return 0;
}