#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size : ";
    cin>> size;
    vector<int>vec(size);
    for (int i = 0; i < size; ++i) { 
        cin >> vec[i];
    }

    cout << "Inputs are: " << endl;
    for (int i = 0; i < size; ++i) {
        cout << vec[i] << " "; 
    }
}