#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr={1,2,4,6,3,7};
    int n=arr.size();
    vector<int> pSum(n, 0);
    pSum[0] = arr[0];
    for(int i=1; i<n;i++){
        pSum[i]=pSum[i-1]+arr[i];
    }
    vector<pair<int,int>> queries={{1,3},{2,4},{0,4}};
    
    for(auto query:queries){
        int l=query.first;
        int r=query.second;
        int sum=0;
        if(l==0){
            sum=pSum[r];
        }
        else{
            sum=pSum[r]-pSum[l-1];
        }
        cout <<sum << endl;
    }
    
    return 0;
}