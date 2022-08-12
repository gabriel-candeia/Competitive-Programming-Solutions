#include<bits/stdc++.h>
using namespace std;

string solve(string s){
    string answ = "", aux = "";
    for(int i=0;i<s.size();i++){
        if(i&1){
            answ.push_back(s[i]);
        }
        else{
            aux.push_back(s[i]);
        }
    }
    reverse(aux.begin(),aux.end());
    return answ + aux;
}

int main(){
    string s;
    cin >> s;
    cout << solve(s) <<"\n";


    return 0;
}