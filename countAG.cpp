//carry forward technique (count)

#include<iostream>
using namespace std;
int main(){
    string s="abcgabgaax";
    int counta=0;
    int ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='a'){
            counta++;
        }
        else if(s[i]=='g'){
            ans+=counta;
        }
    }
    cout<<ans<<endl;
    return 0;
}