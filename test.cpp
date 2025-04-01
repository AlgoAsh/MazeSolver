#include <iostream>
#include <queue>

using namespace std;

const int ROWS = 5, COLS = 5;
char maze[ROWS][COLS] = {
    {'S', '.', '.', '#', '.'},
    {'#', '#', '.', '#', '.'},
    {'.', '.', '.', '.', '.'},
    {'.', '#', '#', '#', '.'},
    {'.', '.', '.', '.', 'E'}
};

// Directions: Right, Left, Down, Up
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// BFS function
bool bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    
    bool visited[ROWS][COLS] = {false};
    visited[startX][startY] = true;

    int nodesExplored = 0;

    while (!q.empty()) {
        pair<int, int> front = q.front();
        int x = front.first, y = front.second;
        q.pop();
        nodesExplored++;

        // If we reach 'E', return true
        if (maze[x][y] == 'E') {
            cout << "Path found!" << endl;
            cout << "Nodes explored: " << nodesExplored << endl;
            return true;
        }

        // Explore neighbors
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS && 
                maze[nx][ny] != '#' && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    cout << "No path found!" << endl;
    cout << "Nodes explored: " << nodesExplored << endl;
    return false;
}

int main() {
    bfs(0, 0); // Start BFS from 'S' position
    return 0;
}
