#include<bits/stdc++.h>
using namespace std;

void construct(string& s, int i){
    if(i==s.size()){
        return;
    }
    if(s[i]=='r'){
        cout << i+1 <<"\n";
        construct(s,i+1);
        return;
    }
    construct(s,i+1);
    cout << i+1 <<"\n";
}

int main(){
    string s;
    cin >> s;
    construct(s,0); 
    return 0;
}