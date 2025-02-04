#include<bits/stdc++.h>
using namespace std;

    int maxAscendingSum(vector<int>& nums) {
        int maxSum=nums[0];
        int curSum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                curSum+=nums[i];
            }else{
                curSum=nums[i];
            }
            maxSum=max(maxSum,curSum);
        }
        return maxSum;
    }
    int main(){
        vector<int> nums={2,15,8,43,23};
        cout<<maxAscendingSum(nums);
    }