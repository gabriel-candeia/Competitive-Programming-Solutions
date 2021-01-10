#include<bits/stdc++.h>
#define ll long long
#define maxn 64
using namespace std;

const ll mod = 1e9+7;
ll cnt[maxn];

ll convert(char c){
    if('0'<=c && c<='9')
        return c-'0';
    else if('A'<=c && c<='Z')
        return (c-'A')+10;
    else if('a'<=c && c<='z')
        return (c-'a')+36;
    else if('-'==c)
        return 62;
    else if('_'==c)
        return 63;
}

int main(){
    for(int i=0;i<64;i++){
        cnt[i]++;
        for(int j=i+1;j<64;j++)
            cnt[i&j]+=2;
    }
    
    string s;
    ll answ = 1;
    cin >> s;
    for(auto c:s)
        answ = (answ*cnt[convert(c)])%mod;

    cout << answ <<'\n';

    return 0;
}