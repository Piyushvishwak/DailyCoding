#include<bits/stdc++.h>
using namespace std;
void permute(string s, int n, int i){
    if(i==n){
        cout<<s<<endl;
        return;
    }
    for(int j=i;j<=n;j++){
        swap(s[i],s[j]);
        permute(s,n,i+1);
        swap(s[i],s[j]);     //backtrack
    }


}
int main(){
    string s="abc";
    int n=s.length()-1;
    permute(s,n,0);
}