#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {1, 3, 3,3, 7, 9};
    int s=0;
    int target = 3;
    int e=arr.size();
    int ans=e;
    while(s<e){
        int mid=s+(e-s)/2;
        if(arr[mid]>target){
            ans=mid;
            e=mid;
        }
        else{
            s=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}