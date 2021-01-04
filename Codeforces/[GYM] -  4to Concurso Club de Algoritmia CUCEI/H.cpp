#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e4+1)
using namespace std;

const ll mod = 1e9+7;
ll fat[maxn], inv[maxn], comb[maxn][maxn];

ll binpow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y&1) ans = (ans*x)%mod;
        x = (x*x)%mod;
        y >>= 1;
    }
    return ans;
}

ll cc(ll a, ll b){
    return (((fat[a]*inv[b])%mod)*inv[a-b])%mod;
}

void precomp(){
    fat[0] = fat[1] = 1;
    for(int i=2;i<maxn;i++){
        fat[i] = (i*fat[i-1])%mod;
    }
    for(int i=0;i<maxn;i++){
        inv[i] = binpow(fat[i],mod-2);
    }
    for(int i=1;i<maxn;i++){
        for(int j=0;j<=i;j++){
            comb[i][j] = cc(i,j);
            if(j) comb[i][j] = (comb[i][j]+comb[i][j-1])%mod;
        } 
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t, n, a, b;

    cin >> t;
    precomp();
    while(t--){
        cin >> n >> a >> b;
        ll answ = 0;
        if(a>n)
            answ = 0;
        else if(b>n)
            answ = (comb[n][n]-comb[n][a-1])%mod;
        else
            answ = (comb[n][b] - comb[n][a-1])%mod;
        cout << (answ+mod)%mod <<'\n';
    }

    return 0;
}
