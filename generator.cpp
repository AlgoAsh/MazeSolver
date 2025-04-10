#include "generator.h"

Generator::Generator(int rows, int cols) {
    ROWS = rows;
    COLS = cols;
    maze.resize(ROWS, vector<Cell>(COLS));
}


bool Generator::isValid(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && !maze[x][y].visited);
}

void Generator::removeWall(Cell &current, Cell &next, int dir) {
    if (dir == 0) { // Up
        current.topWall = false;
        next.bottomWall = false;
    } else if (dir == 1) { // Down
        current.bottomWall = false;
        next.topWall = false;
    } else if (dir == 2) { // Left
        current.leftWall = false;
        next.rightWall = false;
    } else if (dir == 3) { // Right
        current.rightWall = false;
        next.leftWall = false;
    }
}

void Generator::generateMaze(int startX, int startY) {
    stack<pair<int, int>> stk;
    stk.push({startX, startY});
    maze[startX][startY].visited = true;

    while (!stk.empty()) {
        int x = stk.top().first;
        int y = stk.top().second;

        vector<int> dirs = {0, 1, 2, 3};
        shuffle(dirs.begin(), dirs.end(), default_random_engine(rand()));

        bool moved = false;
        for (int dir : dirs) {
            int nx = x + (dir == 2 ? -1 : dir == 3 ? 1 : 0);
            int ny = y + (dir == 0 ? -1 : dir == 1 ? 1 : 0);

            if (isValid(nx, ny)) {
                removeWall(maze[x][y], maze[nx][ny], dir);
                stk.push({nx, ny});
                maze[nx][ny].visited = true;
                moved = true;
                break;
            }
        }
        if (!moved)
            stk.pop();
    }
}

void Generator::printMaze() {
    int displayRows = ROWS * 2 + 1;
    int displayCols = COLS * 2 + 1;

    vector<vector<char>> display(displayRows, vector<char>(displayCols, '#'));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int x = i * 2 + 1;
            int y = j * 2 + 1;
            display[x][y] = ' ';

            if (!maze[i][j].topWall)
                display[x - 1][y] = ' ';
            if (!maze[i][j].bottomWall)
                display[x + 1][y] = ' ';
            if (!maze[i][j].leftWall)
                display[x][y - 1] = ' ';
            if (!maze[i][j].rightWall)
                display[x][y + 1] = ' ';
        }
    }

    display[1][1] = 'S';  // Start
    display[displayRows - 2][displayCols - 2] = 'E';  // End

    for (int i = 0; i < displayRows; i++) {
        for (int j = 0; j < displayCols; j++) {
            cout << display[i][j];
        }
        cout << endl;
    }
}
