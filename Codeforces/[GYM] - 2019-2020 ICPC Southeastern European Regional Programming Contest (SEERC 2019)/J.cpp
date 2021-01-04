#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
using namespace std;

ll n;
vector<pair<ll,ll>> adj[maxn];

int main(){
    cin >> n;
    ll x, y, w;
    for(ll i=0;i<(n*(n-1))/2;i++){
        cin >> x >> y >> w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }

    ll answ=0;
    bool winner = false;
    for(ll i=1;i<=n;i++){
        sort(adj[i].rbegin(),adj[i].rend());
        for(ll j=0;j<(ll)adj[i].size();j+=2)
            answ += adj[i][j].first;
    }

    cout << answ <<'\n';
    return 0;
}