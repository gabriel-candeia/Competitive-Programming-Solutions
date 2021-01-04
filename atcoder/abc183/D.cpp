#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define ll long long
using namespace std;

vector<ll> adj[maxn];

int main(){ 
    ll n, x, s, t, w;

    cin >> n >> w;
    for(int i=0;i<n;i++){
        cin >> s >> t >> x;
        adj[s].push_back(x);
        adj[t].push_back(-x);
    }

    ll rem=0, poss=true;
    for(int i=0;i<maxn;i++){
        for(auto v:adj[i])
            rem+=v;
        if(rem>w)
            poss = false;
    }

    cout << (((poss) ? "Yes" : "No")) <<'\n';

    return 0;
}