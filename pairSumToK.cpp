#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {1,-2,3,8,5,7,6};
    int k = 11;
    unordered_map<int,int> mp;
    for(int i = 0 ; i < arr.size() ; i++){
        int x = k - arr[i];
        if(mp.find(x)!=mp.end()){
            cout<<x<<" , "<<arr[i]<<endl;
            break;
        }
        mp[arr[i]] = i;
    }
    return 0;
}
