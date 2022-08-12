#include<bits/stdc++.h>
using namespace std;

string s;
int cnt(int i){
    int answ = 0;
    if(i-2>=0)
        answ += (s[i-2]=='a' && s[i-1]=='b' && s[i]=='c');
    if(i-1>=0 && i+1<s.size())
        answ += (s[i-1]=='a' && s[i]=='b' && s[i+1]=='c');
    if(i+2<s.size())
        answ += (s[i]=='a' && s[i+1]=='b' && s[i+2]=='c');
    return answ;
}

int main(){
    int n, q;
    
    int answ = 0;

    cin >> n >> q;
    cin >> s;

    for(int i=0;i+2<n;i++){
        if(s[i]=='a'&& s[i+1]=='b' && s[i+2]=='c'){
            answ++;
        }
    }

    for(int i=0;i<q;i++){
        int pos;
        char novo;
        cin >> pos >> novo;
        pos--;
        answ -= cnt(pos);
        s[pos] = novo;
        answ += cnt(pos);
        cout << answ <<"\n";
    }

    return 0;
}