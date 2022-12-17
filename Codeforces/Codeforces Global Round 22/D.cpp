#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> vis, ord;
int low, high;

void dfs(int u){
    vis[u] = 1;
    for(auto v:adj[u])
        if(!vis[v])
            dfs(v);
    if(u==0 || u==n+1) return;
    ord.push_back(u);
}
vector<int> temp, rep;

int find(int x){
    //return x;
    if(rep[x]==x) return x;
    return ((rep[x]==0 || rep[x]==n+1) ? x : rep[x] = find(rep[x]));
}

int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> n;
        adj.clear();
        adj.assign(n+10,vector<int>());
        
        rep.assign(n+10,0);
        temp.assign(n+10,0);

        int k = 0;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            temp[i] = x;
            adj[temp[i]].push_back(i);
            if(x>=i)
                k = i;
        }

        vis.assign(n+10,0), ord.clear();
        for(int i=0;i<=n+1;i++)
            if(!vis[i])
                dfs(i);
        reverse(ord.begin(),ord.end());

        cout << k << "\n";
        for(auto x:ord)
            cout << x << " ";
        cout<<"\n";
    }

    return 0;
}


   