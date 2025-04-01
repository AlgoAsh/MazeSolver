#include <iostream>
#include <vector>
#include <utility>

using namespace std;
class heap
{
    
    vector<int>Heap;
    int index = 1;
    public: 
    void push(int x)
    {
        if(x > Heap[2*index])
            swap(Heap[index],Heap[2*index]);
        else if(x > Heap[2*index+1])
            swap(Heap[index],Heap[2*index+1]);
        else
            Heap[index] = x;
        index++;
    }
    void print()
    {
        for(int a: Heap)
        {
            cout<<a << " ";
        }
    }
};
int main()
{
    vector<int> myHeap;
    heap h;
    h.push(10);
    h.push(20);
    h.push(30);

    h.print();

    return 0;
}