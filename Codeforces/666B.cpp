#include<bits/stdc++.h>
#define ll long long
#define maxn int(3e3+3)
using namespace std;

int mxDist = 0;
int dist[maxn][maxn];
vector<int> adj[maxn];
set<pair<int,int>> in[maxn], out[maxn];

int bfs(int s){
    int u;
    queue<int> q;
    q.push(s), dist[s][s] = 1;

    while(q.size()){
        u = q.front(), q.pop();

        for(auto v:adj[u]){
            if(dist[s][v]==0){
                dist[s][v] = dist[s][u]+1;
                q.push(v);
            }
        }
    }
    mxDist = max(mxDist,dist[s][u]-1);
}

int main(){
    int n, m;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        bfs(i);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]--;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[j][i]>0) in[i].insert({dist[j][i],j});
            if(dist[i][j]>0) out[i].insert({dist[i][j],j});
            if(in[i].size()>4) in[i].erase(in[i].begin());
            if(out[i].size()>4) out[i].erase(out[i].begin());
        }
    }


    int best = 0;
    vector<int> answ(4,0);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j==i || dist[i][j]==-1) continue;
            for(auto p1:in[i]){
                if(p1.second==i || p1.second==j) continue;
                for(auto p2:out[j]){
                    if(p2.second==i || p2.second==j || p2.second==p1.second) continue;
                    int comp = dist[p1.second][i] + dist[i][j] + dist[j][p2.second];
                    if(comp>best)
                        best = comp, answ[0] = p1.second, answ[1] = i, answ[2] = j, answ[3] = p2.second;
                }   
            }
        }
    }

    for(auto x:answ){
        cout << x << " ";
    }cout<<"\n";
    return 0;
}