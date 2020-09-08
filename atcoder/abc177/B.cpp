#include<bits/stdc++.h>
using namespace std;

int testa(string s, string t, int i){
    int answ=0;
    for(int j=0;j<t.size();j++){
        answ+=(s[i+j]!=t[j]);
    }
    return answ;
}

int main(){
    string s,t;

    cin >> s >> t;

    int answ = s.size();
    for(int i=0;i<=s.size()-t.size();i++){
        answ = min(answ,testa(s,t,i));
    }
    cout << answ <<'\n';

    return 0;
}