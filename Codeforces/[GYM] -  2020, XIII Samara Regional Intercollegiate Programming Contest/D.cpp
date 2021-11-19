#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

int n, m;
vector<pair<int,char>> adj[maxn];

vector<int> bfs(int s){
    vector<int> dist(n+1,0);
    queue<int> q;
    int u;

    q.push(s);
    dist[s] = 1;

    while(q.size()){
        u = q.front(), q.pop();
        for(auto e:adj[u]){
            int v = e.first;
            if(dist[v]==0){
                dist[v] =  dist[u]+1;
                q.push(v);
            }
        }
    }

    return dist;
}

int main(){

    cin >> n >> m;
    
    
    for(int i=0;i<m;i++){
        int a, b;
        char c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    
    vector<int> d1, d2, ok;
    d1 = bfs(1), d2 = bfs(n);
    

    ok.assign(n+1,0);
    for(int i=1;i<=n;i++){
        ok[i] = (d1[i]+d2[i]==d1[n]+1);
    }
    

    string answ = "";
    vector<int> parent(n+1,0), pchar(n+1,0), presente(n+1,0), q;
    q.push_back(1);
    
    
    for(int i=1;i<d1[n];i++){
        vector<pair<char,int>> aux;
        for(auto u:q)
            for(auto e:adj[u])
                if(ok[e.first] && d1[e.first]==i+1){
                    aux.push_back({e.second,e.first});
                    if(parent[e.first]==0 || e.second<pchar[e.first]){
                        parent[e.first] = u;
                        pchar[e.first] = e.second;
                    }
                }

        sort(aux.begin(),aux.end());
        answ.push_back(aux[0].first);
        
        q.clear();
        for(auto e:aux)
            if(e.first==aux[0].first && presente[e.second]==0)
                q.push_back(e.second), presente[e.second] = 1;
        
        for(auto u:q)
            presente[u] = 0;
    }

    cout << d1[n]-1 <<"\n";

    parent[1] = -1;
    vector<int> path;
    for(int i=n;i!=-1;i=parent[i]) path.push_back(i);

    reverse(path.begin(),path.end());

    for(auto x:path)
        cout << x << " ";
    cout<<"\n";

    cout << answ <<"\n";


    return 0;
}