#include<bits/stdc++.h>
#define ll long long
#define N int(2e5+3)
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

ll n, ft[N];

ll lsOne(ll x){
    return x&(-x);
}

ll get(ll r){
    ll sum = 0;
    if(r==0) return 0;
    for(;r;r-=lsOne(r)){
        sum+=ft[r];
    }
    return sum;
}

void update(ll r, ll v){
    for(;r<=n;r+=lsOne(r)){
        ft[r]+=v;
    }
}

ll find(ll x){
    ll l=1, r=n, med=0, answ=0, cmp=0;
    while(l<=r){
        med = l + (r-l)/2;
        cmp = get(med-1);
        if(cmp>x){
            r = med-1;
        }
        else{
            answ = med;
            l = med+1;
        }
    }
    return answ;
}

int main(){
    fastIO();
    vector<ll> p, answ;

    cin >> n;
    p.assign(n,0);
    answ.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> p[i];
    }
    
    for(int i=1;i<=n;i++){
        update(i,i);
    }

    

    for(int i=n-1;i>=0;i--){
        answ[i] = find(p[i]);
        update(answ[i],-answ[i]);
    }

    for(int i=0;i<n;i++){
        cout << answ[i] << ' ';
    }cout << '\n';

    return 0;
}