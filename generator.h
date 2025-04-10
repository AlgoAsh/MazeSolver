#ifndef GENERATOR_H
#define GENERATOR_H

#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

class Generator {
public:
    struct Cell {
        bool visited = false;
        bool topWall = true;
        bool bottomWall = true;
        bool leftWall = true;
        bool rightWall = true;
    };

    int ROWS;
    int COLS;
    vector<vector<Cell>> maze;

    Generator(int rows, int cols);

    bool isValid(int x, int y);
    void removeWall(Cell &current, Cell &next, int dir);
    void generateMaze(int startX, int startY);
    void printMaze();
};

#endif // GENERATOR_H
