#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

ll n, h[maxn], a[maxn], ft[maxn];

ll lsone(ll x){
    return (x&(-x));
}

void update(ll r, ll v){
    for(;r<maxn;r+=lsone(r))
        ft[r]=max(ft[r],v);
}

ll get(ll r){
    ll answ = 0;
    if(!r) return 0;
    for(;r;r-=lsone(r))
        answ = max(answ,ft[r]);
    return answ;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> h[i];
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<n;i++)
        update(h[i],get(h[i]-1)+a[i]);
        
    cout << get(n) <<'\n';
    return 0;
}