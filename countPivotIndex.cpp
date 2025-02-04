#include <iostream>
using namespace std;
int main(){
    int arr[] = {1, 7, 3, 6, 5, 6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int leftSum=0;

    for(int i=0;i<n;i++){
        if(leftSum==sum-arr[i]-leftSum){
            cout<<i<<endl;
            break;
        }
        leftSum+=arr[i];
    }
    return 0;
}