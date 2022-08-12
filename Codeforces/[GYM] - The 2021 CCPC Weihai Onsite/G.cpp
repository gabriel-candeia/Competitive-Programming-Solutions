#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ll long long
using namespace std;


const ll mod = 998244353;
ll fat[maxn], inv[maxn];

ll binpow(ll x, ll y){
    ll answ = 1;
    for(;y;y>>=1){
        if(y&1){
            answ = (answ*x)%mod;
        }
        x = (x*x)%mod;
    }
    return answ;
}


ll comb(ll n, ll k){
    if(n<k) return 0;
    return (((fat[n]*inv[k])%mod)*inv[n-k])%mod;
}

void precomp(){
    fat[0] = 1;
    for(int i=1;i<maxn;i++)
        fat[i] = (fat[i-1]*i)%mod;
    for(int i=0;i<maxn;i++)
        inv[i] = binpow(fat[i],mod-2);
}

int freq[maxn];



int main(){
    fastio();
    precomp();
    int n, m;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        freq[x]++;
    }

    vector<int> valores;
    for(int i=0;i<maxn;i++){
        if(freq[i])
            valores.push_back(i);
    }
    
    vector<int> answ(m+1,0);
    for(int i=1;i<=m;i++){
        answ[i] = 1;
        for(auto j:valores){
            answ[i] = (answ[i]*binpow(comb(i,j),freq[j]))%mod;
        }
    }

    for(int i=1;i<=m;i++){
        cout << answ[i] << "\n";
    }

    return 0;
}