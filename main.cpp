#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<vector<char>> loadmaze(const string& filename)
{
    vector<vector<char>> maze;
    ifstream file(filename);
    if(!file)
    {
        cerr<<"Error : Could not open file! " << endl;
        exit(1);
    }
    string line;
    while(getline(file,line))
    {
        vector<char>row(line.begin(), line.end());
        maze.push_back(row);
    }
    file.close();
    return maze;
}
void displayMaze(const vector<vector<char>>&maze)
{
    for(const auto&row: maze)
    {
        for(char cell : row)
        {
            cout<<cell;
        }
        cout<<endl;
    }
}
int main()
{
    string filename = "maze/maze2.txt";
    vector<vector<char>>maze = loadmaze(filename);
    cout<<"Maze loaded successfully : \n";
    displayMaze(maze);
    return 0;
}