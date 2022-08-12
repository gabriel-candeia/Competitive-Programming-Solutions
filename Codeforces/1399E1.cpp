#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e5+5)
using namespace std;

ll sub[maxn], wt[maxn];
vector<pair<int,int>> adj[maxn];

void precomp(int u, int p){
    sub[u] = (p!=-1 && adj[u].size()==1);
    for(auto e:adj[u]){
        int v = e.first;
        if(v!=p){
            wt[v] = e.second;
            precomp(v,u);
            sub[u] += sub[v];
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; ll s;
        cin >> n >> s;
        for(int i=1;i<=n;i++)
            adj[i].clear(), sub[i] = 0, wt[i] = 0;

        for(int i=0;i<n-1;i++){
            int a, b, c;
            cin  >> a >> b >> c;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }

        precomp(1,-1);

        ll soma = 0;
        priority_queue<pair<ll,int>> pq;
        for(int i=1;i<=n;i++){
            soma += wt[i]*sub[i];
            pq.push({(wt[i]/2+wt[i]%2)*sub[i],i});
        }
        
        int moves = 0;
        ll valor, u;
        while(soma>s){
            moves++;
            tie(valor,u) = pq.top(), pq.pop();

            soma -= wt[u]*sub[u];
            wt[u]/=2;
            soma += wt[u]*sub[u];

            pq.push({(wt[u]/2+wt[u]%2)*sub[u],u});
        }

        cout << moves <<"\n";

    }

    return 0;
}