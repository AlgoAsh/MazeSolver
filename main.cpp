#include "solver.h"
#include "generator.h"
int main() {
//     Solver s;

//     string filename = "maze/maze5.txt";
//     if (!s.loadMaze(filename)) {
//         return 1;
//     }
//     s.mazeCopy = s.maze;
        
//     s.estimateBFSMemoryUsage(s.ROWS, s.COLS);
//     size_t memBefore = s.getCurrentMemoryUsage();
//     auto startTime = chrono::high_resolution_clock::now();
//     s.bfs(1,0);
//     auto endTime = chrono::high_resolution_clock::now();
//     size_t memAfter = s.getCurrentMemoryUsage();
//     s.estimateBFSMemoryUsage(s.ROWS, s.COLS);
//     cout << "Memory used (system reported): " << (memAfter - memBefore) << " KB\n";
//     auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
//     cout << "Execution Time: " << duration << " ms" << endl;
//     cout << "Original Maze:\n";
//     s.printMaze(s.mazeCopy);
//     cout << "-----------------------------\n";
//     return 0;   
    
    srand(time(0));

    cout<<"Enter the width and height of maze : " ;
    int w,h;
    cin>>w>>h;
    Generator g(w,h);

    g.generateMaze(0, 0);
    g.printMaze();

    return 0;
}
