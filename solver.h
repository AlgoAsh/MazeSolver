#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#include <chrono>
#include <thread>

#ifdef _WIN32
#include <windows.h>
#include <psapi.h>
#else
#include <sys/resource.h>
#endif

using namespace std;

struct Node {
    int x, y;
    Node(int _x, int _y) : x(_x), y(_y) {}
};

class Solver {
public:
    vector<vector<char>> maze;
    vector<vector<char>> mazeCopy;
    int ROWS, COLS;
    int dx[4] = {0, 0, 1, -1};  
    int dy[4] = {1, -1, 0, 0};

    size_t getCurrentMemoryUsage();

public:
    Solver();  // constructor
    bool loadMaze(const string& filename);
    void printMaze(const vector<vector<char>>& input);
    bool bfs(int startX, int startY);
    void estimateBFSMemoryUsage(int rows, int cols, int estimatedQueueSize = 1000);
    void clearScreen();
};

#endif // SOLVER_H
