#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
using namespace std;

ll n, m, q, k;
vector<int> adj[maxn], dist, source;

ll bb(ll x){
    ll l = 0, r = x, med, answ=-1, cmp;
    while(l<=r){
        med = (l+r)/2;
        cmp = k*(((med+1)*med)/2);
        if(cmp>=x){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }   
    return answ;
}

int main(){
    cin >> n >> m >> q >> k;

    source.assign(q,0);
    for(auto &x:source)
        cin >> x;
    
    dist.assign(n+1,0);

    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    for(auto u:source){
        dist[u] = 1;
        q.push(u);
    }

    int u;
    while(q.size()){
        u = q.front(), q.pop();

        for(auto v:adj[u]){
            if(dist[v]==0){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }

    for(int i=1;i<n;i++){
        cout << bb(dist[i]-1) <<" ";
    }
    cout << bb(dist[n]-1) << "\n";

    return 0;
}