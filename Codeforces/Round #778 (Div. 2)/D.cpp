#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define maxn int(2e5+5)
using namespace std;

int n;
const ll mod = 998244353;
vector<array<ll,3>> adj[maxn];
int sieve[maxn];

ll binpow(ll x, ll y){
    ll answ = 1;
    for(;y;y>>=1){
        if(y&1)
            answ = (answ*x)%mod;
        x = (x*x)%mod;
    }
    return answ;
}

ll inv(ll x){
    return binpow(x,mod-2);
}

void precomp(){
    sieve[0] = sieve[1] = 1;
    for(ll i=2;i<maxn;i++){
        if(sieve[i]==0){
            sieve[i] = i;
            for(ll j=i*i;j<maxn;j+=i){
                sieve[j] = i;
            }
        }
    }
}

ll answ = 1;
int fatora[maxn], melhor[maxn];
void getLcm(int u, int p){
    for(auto e:adj[u]){
        ll v = e[0], a = e[1], b = e[2];
        if(v!=p){
            while(a!=1){
                int d = sieve[a];
                while(a%d==0) a/=d, fatora[d]--;
            }
            while(b!=1){
                int d = sieve[b];
                while(b%d==0) b/=d, fatora[d]++;
                if(melhor[d]<fatora[d]) 
                    answ = (answ*binpow(d,fatora[d]-melhor[d]))%mod, melhor[d] = fatora[d];
            }
            getLcm(v,u);
            a = e[1], b = e[2];
            while(b!=1){
                int d = sieve[b];
                while(b%d==0) b/=d, fatora[d]--;
            }
            while(a!=1){
                int d = sieve[a];
                while(a%d==0) a/=d, fatora[d]++;
            }
        }
    }
}

ll ransw = 0;
void solve(int u, int p, ll aux){
    ransw = (ransw+aux)%mod;
    for(auto e:adj[u]){
        int v = e[0], a = e[1], b = e[2];
        if(v!=p){
            solve(v,u,(((aux*a)%mod)*inv(b))%mod);
        }
    }
}

int main(){
    fastio();
    precomp();
    int t;
    cin >> t;

    while(t--){
        answ = 1, ransw = 0;
        cin >> n;

        for(int i=0;i<n-1;i++){
            int a, b,c,d;
            cin >> a >> b >> c >> d;
            ll aux = __gcd(c,d);
            adj[a].push_back({b,d/aux,c/aux});
            adj[b].push_back({a,c/aux,d/aux});
        }
        
        getLcm(1,-1);
        solve(1,-1,answ);
        cout << ransw <<"\n";

        for(int i=1;i<=n;i++){
            for(auto e:adj[i]){
                int a = e[1];
                while(a!=1){
                    int d = sieve[a];
                    while(a%d==0) a/=d, fatora[d]=melhor[d]=0;
                }
                a = e[2];
                while(a!=1){
                    int d = sieve[a];
                    while(a%d==0) a/=d, fatora[d]=melhor[d]=0;
                }
            }
            adj[i].clear();
        }   
    }

    return 0;
}