#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e6+5)
using namespace std;

const ll mod = 1e9+7;
ll pot[maxn];

void precomp(){
    pot[0] = 0;
    for(int i=1;i<maxn;i++)
        pot[i] = (pot[i-1]*2+1)%mod;
}

int main(){
    int n;
    string s;

    cin >> s;
    

    precomp();
    reverse(s.begin(),s.end());
    while(s.size() && s.back()=='b') s.pop_back();
    reverse(s.begin(),s.end());

    n = s.size();

    ll answ = 0;
    int dead = 0, cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            cnt++;
        }
        else{
            answ = (answ + pot[cnt])%mod;
        }
    }

    cout << answ <<"\n";

    return 0;
}

