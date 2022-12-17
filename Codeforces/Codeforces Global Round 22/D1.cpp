#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> vis, ord;

void dfs(int u){
    vis[u] = 1;
    for(auto v:adj[u])
        if(!vis[v])
            dfs(v);

    ord.push_back(u);
}


int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> n;
        adj.assign(n+1,vector<int>());
        vector<int> temp;
        temp.assign(n+1,0);

        int k = -1;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            temp[i] = x;
            
            if(x<=n && x>0)
                adj[x].push_back(i);
            if(x>=i)
                k = i;
        }

        for(int i=1;i<=n;i++){
            if(temp[i]==n+1 && (i!=k)){
                adj[i].push_back(k);
            }
            if(temp[i]==0 && (i!=k)){
                adj[i].push_back(k);
            }
        }

        vis.assign(n+1,0), ord.clear();
        for(int i=1;i<=n;i++)
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


   