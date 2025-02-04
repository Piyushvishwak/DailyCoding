#include<bits/stdc++.h>
using namespace std;



//recursive

void generate(int n,string s, int open, int close){
    if(s.length()==2*n){
        cout<<s;
        return;
    }
    if(open<n){
        generate(n,s+'(',open+1,close);
    }
    if(close<open){
        generate(n,s+')',open,close+1);
    }
}
int main(){
    int n;
    cin>>n;
    string s="";
    int open=0;
    int close=0;
    generate(n,s,open,close);
    cout<<s;

}