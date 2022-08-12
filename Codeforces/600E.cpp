#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ll long long
using namespace std;

vector<int> adj[maxn];
ll color[maxn], answ[maxn];
vector<map<ll,ll>> mp, mpp;

void merge(map<ll,ll> &a, map<ll,ll> &af, map<ll,ll> &b,  map<ll,ll> &bf){
    if(a.size()<b.size()) 
        swap(a,b), swap(af,bf);
    for(auto c:b){
        af[c.second+a[c.first]]+=c.first;
        a[c.first]+=c.second;
    }
    b.clear(), bf.clear();
}

void solve(int u, int p){
    mp[u][color[u]]++;
    mpp[u][1] = color[u];
    for(auto v:adj[u]){
        if(v!=p){
            solve(v,u);
            merge(mp[u],mpp[u],mp[v],mpp[v]);   
        }
    }
    answ[u] = mpp[u].rbegin()->second;
}

int main(){
    fastio();
    int n;

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> color[i];
    }

    for(int i=0;i<n-1;i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    mp.assign(n+1,map<ll,ll>());
    mpp.assign(n+1,map<ll,ll>());
    solve(1,-1);

    for(int i=1;i<=n;i++){
        cout << answ[i] << " ";
    }cout<<"\n";

    return 0;
}