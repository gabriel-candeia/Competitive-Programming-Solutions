#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define maxn int(1e6+5)
#define ll long long
using namespace std;

ll n, ft[maxn], x, cnt=0;

ll lsOne(ll x){
    return x&(-x);
}

void update(int r, int v){
    for(;r<=n;r+=lsOne(r))
        ft[r]+=v;
}

ll query(int r){
    if(!r) return 0;
    ll sum = 0;
    for(;r;r-=lsOne(r))
        sum+=ft[r];
    return sum;
}

ll query(int l, int r){
    return query(r)-query(l-1);
}

int main(){
    fastio();
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        cnt+=query(x,n);
        update(x,1);
    }
    
    if(cnt%2==(3*n)%2)
        cout << "Petr\n";
    else
        cout << "Um_nik\n";
    return 0;
}