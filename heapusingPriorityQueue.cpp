// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>
using namespace std;

int main() {
    // STL
    // priority_queue<int> h; //Max Heap by Default
    priority_queue<int,vector<int>, greater<int> > h;
    
    h.push(5);
    h.push(5);
    h.push(8);
    h.push(3);
    h.push(2);
    h.push(1);
    
    while(!h.empty()){
        cout<< h.top() <<", ";
        h.pop();
    }
    
    return 0;
}