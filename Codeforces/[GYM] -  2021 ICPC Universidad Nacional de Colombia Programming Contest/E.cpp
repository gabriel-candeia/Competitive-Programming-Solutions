#include<bits/stdc++.h>
#define maxn int(5e5+5)
using namespace std;

vector<int> answ, adj[maxn], visited;
void solve(int u, int p, bool right){
    int n = adj[u].size()/2;
    if(!right)
        n--;
    for(int i=0;i<n;i++){
        if(adj[u][i]!=p)
            solve(adj[u][i],u,1);
        else
            n++;
    }
    answ.push_back(u);
    for(int i=n;i<adj[u].size();i++){
        if(adj[u][i]!=p)
            solve(adj[u][i],u,0);
    }
}

int main(){
    int n;

    cin >> n;
    visited.assign(n+1,0);
    for(int i=1;i<=n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    solve(0,-1,1);
    for(auto x:answ)
        cout << x << " ";
    cout<<"\n";

    return 0;
}