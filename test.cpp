#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<vector<char>> maze;
int ROWS, COLS;

int dx[] = {0, 0, 1, -1};  // Right, Left, Down, Up
int dy[] = {1, -1, 0, 0};

struct Node {
    int x, y;
    Node(int _x, int _y) : x(_x), y(_y) {}
};

void printMaze() {
    for (const auto &row : maze) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

bool bfs(int startX, int startY) {
    queue<Node> q;
    q.push(Node(startX, startY));

    vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
    vector<vector<pair<int, int>>> parent(ROWS, vector<pair<int, int>>(COLS, {-1, -1}));
    visited[startX][startY] = true;

    int nodesExplored = 0;

    while (!q.empty()) {
        Node current = q.front();
        q.pop();
        nodesExplored++;

        if (maze[current.x][current.y] == 'E') {
            cout << "Path found!\n";
            cout << "Nodes explored: " << nodesExplored << endl;

            vector<pair<int, int>> path;
            int x = current.x, y = current.y;
            while (!(x == startX && y == startY)) {
                path.push_back({x, y});
                tie(x, y) = parent[x][y];
            }
            path.push_back({x, y});
            reverse(path.begin(), path.end());

            for (const auto &p : path) {
                if (maze[p.first][p.second] != 'S' && maze[p.first][p.second] != 'E') {
                    maze[p.first][p.second] = '~';
                }
            }

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

            if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS && maze[nx][ny] != '#' && !visited[nx][ny]) {
                q.push(Node(nx, ny));
                visited[nx][ny] = true;
                parent[nx][ny] = {current.x, current.y};
            }
        }
    }

    cout << "No path found!" << endl;
    cout << "Nodes explored: " << nodesExplored << endl;
    return false;
}

bool loadMaze(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open file " << filename << endl;
        return false;
    }

    vector<vector<char>> tempMaze;
    string line;
    
    while (getline(file, line)) {
        if (!line.empty()) {
            tempMaze.push_back(vector<char>(line.begin(), line.end()));
        }
    }

    file.close();

    if (tempMaze.empty()) {
        cerr << "Error: Maze file is empty!" << endl;
        return false;
    }

    // Set global ROWS and COLS
    ROWS = tempMaze.size();
    COLS = tempMaze[0].size();
    
    // Assign the dynamically loaded maze
    maze = tempMaze;

    return true;
}

int main() {
    string filename = "maze/maze3.txt";
    if (!loadMaze(filename)) {
        return 1;
    }

    cout << "Original Maze:\n";
    printMaze();
    cout << "-----------------------------\n";
    bfs(1,1);
    return 0;   
}
