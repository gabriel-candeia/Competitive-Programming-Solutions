#include<bits/stdc++.h>
#define maxn 2505
#define ll long long
using namespace std;

ll n, m;
vector<array<ll,3>> edges;
vector<ll> parent, dist;

vector<ll> bellman_ford(){
    dist.assign(n+1,0), parent.assign(n+1,-1);
    int change=-1;
    for(int i=0;i<n;i++){
        change = -1;
        for(auto e:edges){
            if(dist[e[0]]+e[2]<dist[e[1]]){
                dist[e[1]] = dist[e[0]]+e[2];
                parent[e[1]] = e[0];
                change = e[1];
            }
        }
    }
    vector<ll> cycle;
    if(change==-1) return cycle;
    for(int i=0;i<n;i++) change = parent[change];
    for(int v=change;v!=change || cycle.size()==0;v=parent[v]) 
        cycle.push_back(v);
    cycle.push_back(change);
    reverse(cycle.begin(),cycle.end());
    return cycle;
}

int main(){
    ll a, b, c;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }

    auto answ = bellman_ford();
    if(answ.size()){
        cout << "YES\n";
        for(auto x:answ)
            cout << x << " ";
        cout << "\n";
    }
    else{
        cout << "NO\n";
    }
    
    return 0;
}