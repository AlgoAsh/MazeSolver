#include "generator.h"
#include <iostream>
#include <random>
#include <algorithm>
using namespace std;
Generator::Generator(int rows, int cols) {
    // Ensure odd dimensions for proper maze generation
    ROWS = (rows % 2 == 0) ? rows + 1 : rows;
    COLS = (cols % 2 == 0) ? cols + 1 : cols;

    maze.resize(ROWS, std::vector<char>(COLS, '#'));  // Initialize with walls
}

bool Generator::isValid(int x, int y) {
    return (x > 0 && x < ROWS - 1 && y > 0 && y < COLS - 1 && maze[x][y] == '#');
}

void Generator::generateMaze(int startX, int startY) {
    std::random_device rd;
    std::mt19937 g(rd());

    std::stack<std::pair<int, int>> stk;
    stk.push({startX, startY});
    maze[startX][startY] = 'S';  // Mark Start

    std::vector<std::pair<int, int>> directions = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}};

    while (!stk.empty()) {
        auto curr = stk.top();
        int x = curr.first;
        int y = curr.second;

        std::vector<std::pair<int, int>> neighbors;

        for (auto dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (isValid(nx, ny))
                neighbors.push_back({nx, ny});
        }

        if (!neighbors.empty()) {
            std::shuffle(neighbors.begin(), neighbors.end(), g);
            auto next = neighbors[0];
            int nx = next.first;
            int ny = next.second;

            // Remove wall between (x, y) and (nx, ny)
            maze[(x + nx) / 2][(y + ny) / 2] = ' ';
            maze[nx][ny] = ' ';

            stk.push({nx, ny});
        } else {
            stk.pop();
        }
    }

    // Mark End Point at bottom-right open cell
    for (int i = ROWS - 2; i >= 0; --i) {
        for (int j = COLS - 2; j >= 0; --j) {
            if (maze[i][j] == ' ') {
                maze[i][j] = 'E';
                return;
            }
        }
    }
}

void Generator::printMaze() {
    for (const auto& row : maze) {
        for (char cell : row)
            std::cout << cell;
        std::cout << '\n';
    }
}
#include <fstream>  // for file operations

void Generator::saveMazeToFile(const std::string& filename) {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for writing.\n";
        return;
    }

    for (const auto& row : maze) {
        for (const auto& cell : row) {
            outFile << cell;
        }
        outFile << '\n';
    }

    outFile.close();
    std::cout << "Maze saved successfully to " << filename << "\n";
}


// int main() {
//     int rows, cols;
//     cout << "Enter Maze Dimensions (rows cols): ";
//     cin >> rows >> cols;

//     Generator gen(rows, cols);

//     // Start always at (1, 1)
//     gen.generateMaze(1, 1);

//     cout << "\nGenerated Maze:\n";
//     gen.printMaze();

//     return 0;
// }
