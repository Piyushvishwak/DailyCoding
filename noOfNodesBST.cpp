// Que->  no of nodes in bst and bt

#include<iostream>
using namespace std;
int noOfNodes(int n){
    if(n==0 || n==1){
        return 1;
    }
    int count=0;
    for(int i=1;i<=n;i++){
        count+=noOfNodes(i-1)*noOfNodes(n-i);
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    cout<<noOfNodes(n)<<endl;;
    return 0;
}


// optimal solution id using DP->O(N^2)


// class Solution {
//     // Function to return the total number of possible unique BST.
//     static int func(int n, int[] dp){
//         if(n == 0) return 1;
//         if(n == 1) return 1;
        // if(n == 2) return 2;
//         int count = 0;
//         if(dp[n] != -1) return dp[n];
//         for(int i=1;i<=n;i++){
//             count += func(i-1,dp)*func(n-i,dp);
//         }
//         return dp[n] = count;
//     }
//     static int numTrees(int n) {
//         // Your code goes here
//         int[] dp  = new int[n+1];
//         Arrays.fill(dp,-1);
//         return func(n,dp);
//     }
// }