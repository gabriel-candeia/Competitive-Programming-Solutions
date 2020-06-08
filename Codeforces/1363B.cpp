#include<bits/stdc++.h>
using namespace std;

int count(string s, int l, int r, char c){
    int cnt = 0;
    for(int i=l;i<r;i++){
        cnt += (s[i]==c);
    }
    return cnt;
}

int main(){
    int t, answ;
    string s;
    
    cin >> t;
    while(t--){
        cin >> s;
        answ = 1000;
        for(int i=0;i<s.size();i++){
            answ = min(answ,count(s,0,i,'0')+count(s,i,s.size(),'1'));
            answ = min(answ,count(s,0,i,'1')+count(s,i,s.size(),'0'));
        }
        cout << answ << '\n';
    }

    return 0;
}