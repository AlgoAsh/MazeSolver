#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
using namespace std;

extern vector<vector<char>> maze;
extern int ROWS, COLS;

void generateMaze(int rows, int cols, double wallProbability);
pair<int, int> placeStartEnd();

#endif