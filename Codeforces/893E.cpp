#include<bits/stdc++.h>
#define ll long long
#define N int(2e6+5)
using namespace std;

const ll mod = 1e9+7;
ll fat[N];

ll binpow(ll x, ll y){
    ll result = 1;
    while(y){
        if(y%2){
            result=(result*x)%mod;
        }
        x = (x*x)%mod;
        y/=2;
    }
    return (result%mod);
}

ll inv(ll x){
    return binpow(x,mod-2);
}

ll comb(ll n, ll m){
    return ((fat[n]*inv(fat[m]))%mod*inv(fat[n-m]))%mod;
}

int main(){
    int q, x, y, cnt, p;
    ll answ=0;
    vector<int> sieve(N,1);

    for(int i=2;i<N;i++){
        if(sieve[i]==1){
            for(int j=i;j<N;j+=i){
                if(sieve[j]==1) sieve[j] = i;
            }
        }
    }
    
    fat[0] = 1;
    for(int i=1;i<N;i++){
        fat[i] = (i*fat[i-1])%mod;
    }

    cin >> q;
    sieve[1] = 2;
    while(q--){
        cin >> x >> y;
        answ = 1;
        while(x!=1){
            cnt=0;
            p = sieve[x];
            while(x%p==0){
                cnt++;
                x/=p;
            }
            answ = (answ*comb(cnt+y-1,y-1))%mod;
        }
        cout << (answ*binpow(2,y-1))%mod << '\n';
    }

    return 0;
}