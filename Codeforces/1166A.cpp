#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, answ=0;
    map<char,int> cnt;
    string s;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        cnt[s[0]]++;
    }

    answ = 0;
    for(auto p:cnt){
        int x = p.second/2;
        answ += x*(x-1) + (p.second-x)*(p.second-x-1);
    }

    cout << answ/2 << '\n';

    return 0;
}