#include<bits/stdc++.h>
#define maxn 205
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

vector<int> adj[maxn];
int visited[maxn], n2;

int dfs(int a, int b, int p){
    visited[a] = -(a==b);
    for(auto v:adj[a])
        if(v!=p)
            visited[a] = min(dfs(v,b,a),visited[a]);
    return visited[a];
}

void dfs2(int a, int p){
    pair<int,int> mx = {0,0};

    for(auto v:adj[a]){
        if(v!=p && visited[v]>=0)
            dfs2(v,a);
        if(visited[v]>mx.second)
            mx = {mx.second,visited[v]};
        else if(visited[v]>mx.first)
            mx = {visited[v],mx.second};
    }

    n2 = max(n2,mx.first+mx.second);
    visited[a] = mx.second+1;
}


int main(){
    fastio();
    int n, x, y;
    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int answ = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int n1 = -1; n2 = 0;
            memset(visited,0,sizeof(visited));
            dfs(i,j,-1);
            for(int k=1;k<=n;k++) n1 -= visited[k];
            for(int k=1;k<=n;k++)
                if(!visited[k])
                    dfs2(k,-1); 
            answ = max(answ,n1*n2);
        }
    }
    cout<< answ <<'\n';
}