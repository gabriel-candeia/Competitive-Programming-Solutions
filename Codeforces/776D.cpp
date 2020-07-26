#include<bits/stdc++.h>
#define N 100005
using namespace std;

int roomColor[N], switchesColor[N], u;
vector<bool> visited;
vector<int> roomSwitches[N];
vector<vector<pair<int,int>>> adj;


int main(){
    int n, m, x, y;

    cin >> n >> m;
    adj.assign(m+1,vector<pair<int,int>>());
    memset(switchesColor,0,m+1);

    for(int i=1;i<=n;i++){
        cin >> roomColor[i];
    }

    for(int i=1;i<=m;i++){
        cin >> x;
        for(int j=0;j<x;j++){
            cin >> y;
            roomSwitches[y].push_back(i);
        }
    }

    for(int i=1;i<=n;i++){
        x = roomSwitches[i][0];
        y = roomSwitches[i][1];
        adj[x].push_back({y,roomColor[i]});
        adj[y].push_back({x,roomColor[i]});
    }
    queue<int> q;
    visited.assign(m+1,false);
    for(int i=1;i<=m;i++){
        if(!visited[i]){
            visited[i] = true;
            q.push(i);

            while(q.size()){
                u = q.front(); q.pop();
                for(auto v:adj[u]){
                    if(!visited[v.first]){
                        visited[v.first] = true;
                        q.push(v.first);
                        if(v.second==0){
                            roomColor[v.first] = !roomColor[u];
                        }
                        else{
                            roomColor[v.first] = roomColor[u];
                        }
                    }
                }
            }
        }
    }

    bool poss = true;
    for(int u=1;u<=m;u++){
        for(auto v:adj[u]){
            if((v.second==0 && roomColor[v.first]==roomColor[u])||(v.second==1 && roomColor[v.first]!=roomColor[u])){
                poss = false;
            }
        }
    }

    cout << ((poss) ? "YES" :  "NO" )<< '\n';
    return 0;
}