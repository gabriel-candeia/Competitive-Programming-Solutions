#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define maxn int(2e5+5)
using namespace std;

int n, m;
vector<int> adj[maxn];
int v[maxn];

void solve(int u){
    v[u] = 1;
    for(auto w:adj[u]){
        if(!v[w]){
            solve(w);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v[n] = 1;
    solve(n-1);
    v[n] = 0;

    for(int i=1;i<=n;i++){
        cout << ((v[i]==0) ? 'A' : 'B');
    }
    cout <<"\n";

    return 0;
}