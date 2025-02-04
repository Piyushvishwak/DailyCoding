#include<iostream>
using namespace std;
int main(){
    int arr[6]={16,17,4,3,5,2};
    int end=5;
    int max=0;
    int count=0;
    for(int i=end;i>=0;i--){
        if(arr[i]>max){
            count++;
            max=arr[i];
        }
    }
    cout<< count;

    return 0;
}
