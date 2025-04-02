#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

const int ROWS = 5, COLS = 5;
char maze[ROWS][COLS] = {
    {'S', '.', '.', '#', '.'},
    {'#', '#', '.', '#', '.'},
    {'.', '.', '.', '.', '.'},
    {'.', '#', '#', '#', '.'},
    {'.', '.', '.', '.', 'E'}
};

int dx[] = {0, 0, 1, -1};  // Right, Left, Down, Up
int dy[] = {1, -1, 0, 0};  

struct Node {
    int x, y;
    Node(int _x, int _y) : x(_x), y(_y) {}
};

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

bool bfs(int startX, int startY) {

    queue<Node> q;
    q.push(Node(startX, startY));

    bool visited[ROWS][COLS] = {false};  
    pair<int, int> parent[ROWS][COLS];  
    visited[startX][startY] = true;  

    int nodesExplored = 0;  

    while (!q.empty()) {
        Node current = q.front();
        q.pop();
        nodesExplored++;  

        if (maze[current.x][current.y] == 'E') {
            cout << "Path found!\n";
            cout << "Nodes explored: " << nodesExplored << endl;

            //Backtrack to find the path
            vector<pair<int, int>> path;
            int x = current.x, y = current.y;
            while (maze[x][y] != 'S') {
                path.push_back({x, y});
                tie(x, y) = parent[x][y];  // Now move to the parent node
            }
            path.push_back({x, y});  // Include the start position
            reverse(path.begin(), path.end());  

            for (const auto &p : path) {
                if (maze[p.first][p.second] != 'S' && maze[p.first][p.second] != 'E') {
                    maze[p.first][p.second] = '~';  // Mark the path
                }
            }

            //Display the path
            cout << "Path taken: ";
            for (const auto &p : path) { 
                cout << "(" << p.first << "," << p.second << ") ";
            }
            cout << endl;
            printMaze(); 
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS &&
                maze[nx][ny] != '#' && !visited[nx][ny]) {

                q.push(Node(nx, ny));
                visited[nx][ny] = true;
                parent[nx][ny] = {current.x, current.y};  // Store the parent
            }
        }
    }

    cout << "No path found!" << endl;
    cout << "Nodes explored: " << nodesExplored << endl;
    return false;
}

int main() {
    cout<<"Original Maze!"<< endl;
    printMaze();
    cout<<"-----------------------------"<<endl;
    bfs(0, 0);  // Start BFS from 'S'
    return 0;
}
