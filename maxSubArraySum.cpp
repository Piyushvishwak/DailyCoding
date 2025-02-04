//carry forward sum

#include<iostream>
using namespace std;
int main(){
    int a[10]={2,-4,1,5,-3,2,6,-8,7,-3};
    int maxSum = 0;
    int currSum = 0;
    for(int i=0;i<10;i++){
        currSum += a[i];
        if(currSum<0) currSum = 0;
        maxSum = max(maxSum,currSum);
    }
    cout<<maxSum<<endl;

    return 0;
}