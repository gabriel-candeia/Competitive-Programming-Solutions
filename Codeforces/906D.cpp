#include<bits/stdc++.h>
#define ll long long
#define maxn 40
using namespace std;

ll tot(ll n){
    ll answ = n;
    for(ll i=2;i*i<=n;i++){
        while(n%i==0) n/=i;
        answ -= answ/i;
    }
    if(n>1) answ -= answ/n;
    return answ;
}

ll binpow(ll x, ll y, ll mod){
    ll answ = 1;
    for(;y;y/=2){
        if(y&1)
            answ = (answ*x)%mod;
        x = (x*x)%mod;
    }
    return answ;
}

bool safe(ll x, ll y){
    if(x==1) return true;
    ll answ = 1;
    for(int i=0;i<y;i++){
        answ = answ*x;
        if(answ>40)
            return false;
    }
    return true;
}

vector<ll> arr, phi;
ll n, mod, m;

int main(){

    cin >> n >> mod;

    phi.push_back(mod);
    while(phi.back()!=1){
        phi.push_back(tot(phi.back()));
    }
    phi.push_back(1);
    for(auto p:phi){
        cout << p << " ";
    }cout<<"\n";

    arr.assign(n,0);
    for(auto &x:arr){
        cin >> x;
    }
    
    cin >> m;
    for(int i=0;i<m;i++){
        int l, r;
        cin >> l >> r;
        l--, r--;
        r = min(r,l+(int)phi.size()-2);
        ll answ = 1;
        bool flag = true;
        
        for(r;r>=l;r--){
            if(flag)
                flag = safe(arr[r],answ);
            if(flag)
                answ = binpow(arr[r],answ,1e15);
            else
                answ = binpow(arr[r],phi[r+1]+answ%phi[r+1],phi[r]);
        }
        cout << answ%mod <<"\n";
    }
    cout <<"\n";
    return 0;
}