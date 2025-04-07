#ifndef MAZE_H
#define MAZE_H

#include <vector>

extern std::vector<std::vector<char>> maze;
extern std::vector<std::vector<char>> mazeCopy;
extern int ROWS, COLS;

void loadMaze(const std::string& filename);
void printMaze(const std::vector<std::vector<char>>& input);

#endif
