#include "solver.h"
#include "generator.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
int main() {
    cout<<"\t\t<<<<<\tMazeSolver\t>>>>>"<< endl;
    cout<<"\tEnter 1 : Run test on a saved maze"<<endl;
    cout<<"\tEnter 2 : Generate a maze and then run the test."<<endl;
    int choice;
    cout<<"Choice : ";
    cin>>choice;
    cout<<"----------------------------------------------------------------"<<endl;
    if(choice == 1){
            #ifdef _WIN32
            system("dir maze");
            #else
                system("ls maze");
                cout<<"This is a linux/Mac System!"<<endl;
            #endif
            cout<<"----------------------------------------------------------------"<<endl;
            // code to render the maze
            int render;
            cout<<"Press 1 to render any maze else anything to continue : ";
            cin>>render;
            if(render == 1)
            {
                do
                {
                    string path;
                    cout<<"Enter the path of maze file to render(such as maze/maze1.txt): ";
                    cin>>path;
                    ifstream file(path);
                // if(file.bad())
                // {
                //     cout<<"Wrong file input!";
                //     return 1;
                // }
                    if (!file.is_open()) {  // Check if file opened successfully
                    std::cout << "Failed to open the file!" << std::endl;
                    return 1;
                    }
                    std::string line;
                    while (std::getline(file, line)) {  // Read line by line
                    std::cout << line << std::endl;  // Print each line
                    }

                    file.close();
                    cout<<"Press 1 to render any maze else anything to continue : ";
                    cin>>render;
                }while(render==1);
            }
        string path;
        cout<<"Enter the path of maze file to operate on (such as maze/maze1.txt): ";
        cin>>path;
        ifstream file(path);
        if(file.bad())
            {
                cout<<"Wrong file input!";
                return 1;
            }
        int t1,t2;
        cout<<"Enter the coordinates of start(s) position index [row,col] : ";
        cin>>t1>>t2;
    Solver s;

    //string filename = "maze/maze5.txt";
    string filename = path;
    if (!s.loadMaze(filename)) {
        cout<<"Error in opening the file!";
        return 1;
    }
    s.mazeCopy = s.maze;
        
    s.estimateBFSMemoryUsage(s.ROWS, s.COLS);
    size_t memBefore = s.getCurrentMemoryUsage();
    auto startTime = chrono::high_resolution_clock::now();
    s.bfs(t1,t2);
    auto endTime = chrono::high_resolution_clock::now();
    size_t memAfter = s.getCurrentMemoryUsage();
    s.estimateBFSMemoryUsage(s.ROWS, s.COLS);
    cout << "Memory used (system reported): " << (memAfter - memBefore) << " KB\n";
    auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
    cout << "Execution Time: " << duration << " ms" << endl;
    cout << "Original Maze:\n";
    s.printMaze(s.mazeCopy);
    cout << "-----------------------------\n";
    }


    else if(choice == 2){
    srand(time(0));

    cout<<"Enter the width and height of maze : " ;
    int w,h;
    cin>>w>>h;
    Generator g(w,h);

    g.generateMaze(0, 0);
    g.printMaze();
    // Fix here between cell struct and 2D vector of char conflict
    // int t1,t2;
    // cout<<"Enter the coordinates of start(s) position index[row][col] : ";
    // cin >> t1 >> t2;
    
    // Solver s;
    // s.maze= g.maze;
    // s.mazeCopy = s.maze; 
    // s.estimateBFSMemoryUsage(h, w);
    // size_t memBefore = s.getCurrentMemoryUsage();
    // auto startTime = chrono::high_resolution_clock::now();
    // s.bfs(t1,t2);
    // auto endTime = chrono::high_resolution_clock::now();
    // size_t memAfter = s.getCurrentMemoryUsage();
    // s.estimateBFSMemoryUsage(s.ROWS, s.COLS);
    // cout << "Memory used (system reported): " << (memAfter - memBefore) << " KB\n";
    // auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
    // cout << "Execution Time: " << duration << " ms" << endl;
    // cout << "Original Maze:\n";
    // s.printMaze(s.mazeCopy);
    // cout << "-----------------------------\n";
    }
    else
    {
        cout<<"Wrong input, try again!!";
    }
    return 0;
}
