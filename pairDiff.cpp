//use hashset/unordered_map
#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int arr[6] = {1, 5, 3, 4, 2, 4};
    int k = 2, count = 0;
    unordered_map<int, int> freq;

    for(int i = 0; i < 6; i++){
        freq[arr[i]]++;
    }

    for(int x:arr){
        if(freq.find(x-k) != freq.end()){
            count+=freq[x-k];
        }
        if(freq.find(x+k) != freq.end()){
            count+=freq[x+k];
        }
        freq[x]++;
    }

    cout << count;
    return 0;
}