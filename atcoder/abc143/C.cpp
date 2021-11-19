#include<bits/stdc++.h>
using namespace std;

int main(){
    int answ = 1;
    string s;
    int n;
    cin >> n;
    cin >> s;
    for(int i=0;i<s.size()-1;i++){
        answ += (s[i]!=s[i+1]);
    }
    cout <<answ <<"\n";
    return 0;
}