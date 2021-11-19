#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e5+5)
using namespace std;

const ll mod = 1000000007;
ll binpow(ll x, ll y){
    if(y<0) return 1;
    ll result = 1;
    for(;y;y/=2){
        if(y%2){
            result = (result*x)%mod;
        }
        x = (x*x)%mod;
    }
    return result;
}

ll inv(ll x){
    return binpow(x,mod-2);
}

ll f_even(ll k, ll n){
    if(n<=1) return 0;
    ll q = ((k-1)*(k-1))%mod, qtd = (n)/2-1;
    return (((k*(binpow(q,qtd)-1))%mod*inv(q-1))%mod*k)%mod;
}

ll f_odd(ll k, ll n){
    ll q = ((k-1)*(k-1))%mod, qtd = (n)/2;
    return (((k*(binpow(q,qtd)-1))%mod*inv(q-1))%mod*(k-1))%mod;    
}

int ht[maxn];
vector<int> adj[maxn];

void dfs(int u, int p){
    if(p!=-1) ht[u] = ht[p]+1;
    for(auto v:adj[u]){
        if(v!=p)
            dfs(v,u);
    }
}

int main(){
    int n, q;

    cin >> n >> q;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0,-1);
    for(ll i=0;i<q;i++){
        int a, b;
        ll k, x;
        cin >> a >> b >> k;
        x = (k*(i+1))%mod;
        ll rem = n - (ht[b]-ht[a]+1), qtd = (ht[b]-ht[a]+1), temp;
        if(qtd%2)
            temp = ((f_odd(x,qtd-1) - f_even(x,qtd-1))%mod+mod)%mod;
        else
            temp = ((f_even(x,qtd-1) - f_odd(x,qtd-1))%mod+mod)%mod;
        cout << qtd-1 <<'\n';
        cout << f_odd(x,qtd-1) <<"\n";
        cout << (temp*binpow(x-1,rem))%mod << '\n';
    }

    return 0;
}