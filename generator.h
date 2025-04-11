#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <stack>
#include <utility>  // for pair
#include <string>
class Generator {
public:
    Generator(int rows, int cols);

    void generateMaze(int startX, int startY);
    void printMaze();
    void saveMazeToFile(const std::string& filename);
    std::vector<std::vector<char>> maze;  // Public so users can access maze directly if needed

private:
    int ROWS, COLS;

    bool isValid(int x, int y);
};

#endif // GENERATOR_H
