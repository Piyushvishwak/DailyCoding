#include<bits/stdc++.h>
using namespace std;

// 4 Problems
// Next Greater Element
// Next Smaller Element (HW)
// Prev Greater Element (Left to Right)
// Prev Smaller Element (HW)

vector<int> nextGreaterElement(vector<int> &arr){
    stack<int> s;
    vector<int> res(arr.size(),-1);

    for(int i=arr.size()-1;i>=0;i--){
        int current=arr[i];
        while(!s.empty() && current>=s.top()){
            s.pop();
        }
        if(!s.empty()){
            res[i]=s.top();
        }
        s.push(arr[i]);
    }
    return res;
}

int main() {
    vector<int> arr = {4,5,2,25,8,9,13};
    vector<int> result = nextGreaterElement(arr);
    
    for(int x:result){
        cout<< x <<",";
    }

    return 0;
}