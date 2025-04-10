#include "solver.h"

Solver::Solver() {
    ROWS = 0;
    COLS = 0;
}

size_t Solver::getCurrentMemoryUsage() {
#ifdef _WIN32
    PROCESS_MEMORY_COUNTERS memInfo;
    GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo));
    return memInfo.WorkingSetSize / 1024;
#else
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss;
#endif
}

bool Solver::loadMaze(const string& filename) {
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

void Solver::printMaze(const vector<vector<char>>& input) {
    for (const auto& row : input) {
        for (char cell : row) {
            if (cell == '~')
                cout << "\033[1;32m~\033[0m ";
            else
                cout << cell << " ";
        }
        cout << endl;
    }
}

bool Solver::bfs(int startX, int startY) {
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
                    clearScreen();
                    printMaze(maze);
                    //std::this_thread::sleep_for(std::chrono::milliseconds(5));

                }
            }

            cout << "Path taken: ";
            for (const auto &p : path) {
                cout << "(" << p.first << "," << p.second << ") ";
            }
            cout << endl;
            //printMaze(maze);
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS && maze[nx][ny] != '#' && !visited[nx][ny]) {
                q.push(Node(nx, ny));
                visited[nx][ny] = true;
                parent[nx][ny] = {current.x, current.y};

                // Animate step
                if (maze[nx][ny] != 'E') maze[nx][ny] = ' '; // Mark explored node
                //clearScreen();
                //printMaze();
                //std::this_thread::sleep_for(std::chrono::milliseconds(1));
 // adjust speed here
                visited[nx][ny] = true;
                parent[nx][ny] = {current.x, current.y};
            }
        }
        
    }

    cout << "No path found!" << endl;
    cout << "Nodes explored: " << nodesExplored << endl;
    return false;
}


void Solver::estimateBFSMemoryUsage(int rows, int cols, int estimatedQueueSize) {
    size_t visitedMem = rows * cols * sizeof(bool);
    size_t parentMem = rows * cols * sizeof(pair<int, int>);
    size_t queueMem = estimatedQueueSize * sizeof(Node);

    size_t total = visitedMem + parentMem + queueMem;

    cout << "\n--- Estimated BFS Memory Usage ---\n";
    cout << "Visited[][]     : " << visitedMem / 1024.0 << " KB\n";
    cout << "Parent[][]      : " << parentMem / 1024.0 << " KB\n";
    cout << "Queue           : " << queueMem / 1024.0 << " KB\n";
    cout << "Total Estimated : " << total / 1024.0 << " KB\n";
}

void Solver::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
