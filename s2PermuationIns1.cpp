#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1="abc";
    string s2="xyzz";
    string win="";
    if(s1.length()>s2.length()){
        return false;
    }
    vector<int> freq(26,0);
    vector<int> winFreq(26,0);
    for(char ch:s1){
        freq[ch-'a']++;
        
    }
}