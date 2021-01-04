#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

int nxt[27][maxn];
string s, t;

int precomp(string s){
    int n = s.size();
    for(int j='a';j<='z';j++)
        nxt[j-'a'][n] = n;

    for(int i=n-1;i>=0;i--){
        for(int j='a';j<='z';j++)
            nxt[j-'a'][i] = nxt[j-'a'][i+1];    
        nxt[s[i]-'a'][i] = i;
    }
}

string solve(string t, string s){
    int ptr = -1;
    string answ = "";
    for(int i=0;i<t.size();i++){
        ptr = nxt[t[i]-'a'][ptr+1];
        if(ptr==s.size())
            break;
        else
            answ+=t[i];
    }
    if(answ=="")
        answ = "IMPOSSIBLE";
    return answ;
}

int main(){
    int n;
    cin >> s >> n;

    precomp(s);
    for(int i=0;i<n;i++){
        cin >> t;
        cout << solve(t,s) << '\n';
    }

    return 0;
}
