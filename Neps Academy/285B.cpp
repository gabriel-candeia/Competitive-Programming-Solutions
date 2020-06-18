#include<bits/stdc++.h>
#define INF 1E8
using namespace std;


int dfs(vector<vector<int>>& adj,int u,vector<bool>& visited,vector<int>& age){
    visited[u] = true;
    int ret = INF;
    for(auto v:adj[u]){
        if(!visited[v]){
            ret = min(ret,dfs(adj,v,visited,age));    
            ret = min(ret,age[v]);
        }
    }
    return ret;
}


int main(){
    int n, m, I;
    int x, y, temp;;
    char op;
    vector<int> f, age;
    vector<vector<int>> adj;
    

    cin >> n >> m >> I;

    vector<bool> visited(n+10,false);
    adj.assign(n+1,vector<int>());
    age.assign(n+10,0);
    f.assign(n+10,0);

    for(int i=1;i<=n;i++){
        cin >> x;
        age[i] = x;
        f[i] = i;
    }

    for(int i=0;i<m;i++){
        cin >> x >> y;
        adj[y].push_back(x);
    }

    for(int i=0;i<I;i++){
        cin >> op;
        if(op=='T'){
            cin >> x >> y;
            temp = f[x];
            f[x] = f[y];
            f[y] = temp;
            x = f[x]; y = f[y];
            temp  = age[y];
            age[y] = age[x];
            age[x] = temp;
        }
        else{
            cin >> x;   
            visited.assign(n+1,false);
            int val = dfs(adj,f[x],visited,age);
            if(val==INF){
                cout << "*\n";
            }
            else{
                cout <<  val << '\n';
            }
        }
    }
    return 0;
}
