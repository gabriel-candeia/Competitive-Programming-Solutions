#include<bits/stdc++.h>
#define maxn int(3e5+5)
#define ll int
using namespace std;

ll ft[maxn];
ll lsone(ll x){
    return (x&(-x));
}

void update(ll r, ll y){
    if(r==0) return;
    for(;r<maxn;r+=lsone(r))
        ft[r]^=y;
}

ll query(ll r){
    ll sum = 0;
    for(;r;r-=lsone(r)){
        sum ^= ft[r];
    }
    return sum;
}

ll query(ll l, ll r){
    return (query(r)^query(l-1));
}

int main(){
    ll n, q, x, t, y;

    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> x;
        update(i,x);
    }


    for(int i=1;i<=q;i++){
        cin >> t >> x >> y;
        if(t==1){
            update(x,y);
        }
        else{
            cout << query(x,y) <<"\n"; 
        }
    }


    return 0;
}