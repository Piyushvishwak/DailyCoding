#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int maxproduct=nums[0];
        int minproduct=nums[0];
        for(int i=1;i<nums.size();i++){
            if (nums[i] < 0) {
                swap(maxproduct, minproduct);
            }
            maxproduct=max(maxproduct*nums[i],nums[i]);
            minproduct=min(minproduct*nums[i],nums[i]);
            res=max(res,maxproduct);
        }
        return res;
}

int main(){
    
    

    return 0;
}