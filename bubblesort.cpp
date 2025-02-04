#include<bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int> &arr,int n){
    // if(arr.size()==0 || n==1){
    //     return;
    // }
    // for(int i=0;i<arr.size();i++){
    //     for(int j=0;j<i;j++){
    //         if(arr[j]>arr[j+1]){
    //             swap(arr[j],arr[j+1]);
    //         }
    //     }
    //     bubbleSort(arr, n-1);
    // }

    if(n==1){
        return;
    }
    for(int j=0;j<n-1;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
    bubbleSort(arr, n-1);


}
int main(){
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}