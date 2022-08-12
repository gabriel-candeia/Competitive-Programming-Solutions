#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

int n, m;
vector<int> adj[maxn];
int parent[maxn][2];

int visited[maxn];
bool cycle(int u){
    visited[u] = 1;
    bool value = false;
    for(auto v:adj[u]){
        if(!visited[v]){
            value = value || cycle(v);
        }
        else if(visited[v]==1){
            value = 1;
        }
    }
    visited[u] = 2;
    return value;
}

pair<string,vector<int>> solve(int s){
    queue<pair<int,int>> q;
    int u, f;

    q.push({s,0});

    while(q.size()){
        tie(u,f) = q.front(), q.pop();

        for(auto v:adj[u]){
            if(parent[v][1-f]==0){
                parent[v][1-f] = u;
                q.push({v,1-f});
            }
        }
    }

    string result = "Lose";
    vector<int> answ;

    for(int i=1;i<=n;i++){
        if(adj[i].size()==0 && parent[i][1]!=0){
            result = "Win";
            for(int u=i,f=1;!(u==s && f==0);u=parent[u][f],f=1-f){
                answ.push_back(u);
            }
            answ.push_back(s);
            reverse(answ.begin(),answ.end());
            return {result,answ};
        }
    }

    if(cycle(s)) result = "Draw";

    return {result,answ};
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        while(k--){
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }
    int start;
    cin >> start;

    auto p = solve(start);
    
    cout << p.first <<"\n";

    if(p.second.size()){
        for(auto x:p.second){
            cout << x << " ";
        }
        cout<<"\n";
    }
    
    return 0;
}