#include<bits/stdc++.h>
using namespace std;

vector<bool> distColor(int(1e6),false);

int dfs(vector<vector<int>>& adj, int n, int u, vector<bool>& visited, vector<int>& dist, vector<int>& colors, vector<bool>& distColor, int& acm){
    int rval=0;
    visited[u] = true;

    if(distColor[dist[u]]==false && (colors[u]==0)){
        acm++;
        distColor[dist[u]] = true;
    }

    for(auto v : adj[u]){
        if(!visited[v]){
            dist[v] = dist[u]+1;
            rval = max(rval,dfs(adj,n,v,visited,dist,colors,distColor,acm));
        }
        else{
            rval = dist[u]-dist[v]+1;
        }
    }
    return rval;
}

pair<int,int> findCycle(vector<vector<int>>& adj, int n, vector<pair<int,int>> &dg, vector<int>& colors){
    vector<bool> visited(n,false);
    vector<int> dist(n,0);
    int acm1 = 0, acm2 = 0;
    sort(dg.rbegin(),dg.rend());

    for(auto p : dg){
        if(!visited[p.second]){
            acm1 += dfs(adj,n,p.second,visited,dist,colors, distColor,acm2);
            distColor.assign(n,false);
        }
    }

    return make_pair(acm1,min(acm2,acm1));
}

int main(){
    int t, n, m, u, v;
    char r;

    cin >> t;

    while(t--){
        cin >> n >> m;

        vector<int> colors(n*m,0), dg(n*m,0);
        vector<vector<int>> adjR(n*m,vector<int>());

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> r;
                colors[i*m+j] = (r=='1');
            }
        }
        

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> r;
                u = m*i+j;
                v = u + ((r=='L') ? -1 : (r=='R') ? 1 : (r=='U') ? -m : m);
                adjR[v].push_back(u);
                dg[v]++;
            }
        }

        vector<pair<int,int>> dg1;
        for(int i=0;i<n*m;i++){
            dg1.push_back(make_pair(dg[i],i));
        }
        pair<int,int> answ = findCycle(adjR,n*m,dg1,colors);
        cout <<  answ.first << " " << answ.second << '\n';
    }


    return 0;
}