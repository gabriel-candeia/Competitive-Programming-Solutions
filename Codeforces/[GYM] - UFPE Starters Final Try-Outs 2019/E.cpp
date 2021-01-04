#include<bits/stdc++.h>
#define ll long long
using namespace std;


const ll mod = 1e9+7;
ll n;
ll answ = 0;
vector<vector<int>> adj;
ll dfs(ll u, ll p){
    ll acm = 0, temp;
    for(auto v:adj[u]){
        if(v!=p){
            temp = dfs(v,u);
            acm+=temp;
            //cout << u << " " << v << " " << temp <<'\n';
            answ = (answ+temp*(n-temp))%mod;
        }
    }
    return acm+1;
}

ll binpow(ll a, ll b){
    ll result = 1;
    while(b){
        if(b%2)
            result = (result*a)%mod;
        a = (a*a)%mod;
        b/=2;
    }

    return result;
}

ll inv(ll x){
    return binpow(x,mod-2);
}

int main(){
    int x, y;
    cin >> n;
    adj.assign(n+1,vector<int>());
    for(int i=1;i<n;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,-1);
    ll qtd = (n*(n-1))/2 + n;
    cout << (answ*inv(qtd%mod))%mod <<'\n';
    return 0;
}