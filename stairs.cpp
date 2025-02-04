// #include<bits/stdc++.h>
// using namespace std;
// int noOfWays(int n, int k){
//     if(n==0){
//         return 1;
//     }
//     if(n<0){
//         return 0;
//     }
//     int ans=0;
//     for(int i=1;i<=k;i++){
//         ans+=noOfWays(n-i,k);
//     }
//     return ans;
// }

// int main(){
//     int n=4;
//     int k=3;
//     cout<<noOfWays(n,k);


// }




#include<bits/stdc++.h>
using namespace std;
int noOfWays(int n, int k, vector<int> &paths, vector<vector<int>> allPaths  ){
    if(n==0){
        allPaths.push_back(paths);
        return 1;
    }
    if(n<0){
        return 0;
    }
    int ans=0;
    for(int i=1;i<=k;i++){
        paths.push_back(i);
        ans+=noOfWays(n-i,k,paths, allPaths);
        paths.pop_back();
    }
    return ans;
}

int main(){
    int n=4;
    int k=3;
    vector<int> paths;
    vector<vector<int>> allPaths;

    cout<<noOfWays(n,k,paths,allPaths)<<endl;

    for(int i=0;i<paths.size();i++){
        for(int j=0;j<allPaths[0].size();j++){
            cout<<paths[i]<<" ";
        }
    }


}