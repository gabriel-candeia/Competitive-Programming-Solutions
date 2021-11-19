#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int n, m;
int answ = 0;
vector<int> adj[maxn];
vector<int> st;

void dfs(int v){
    if(v==n) return;
    int i=0;
    for(;i<adj[v].size() && adj[v][i]<=v;i++);
    if(i==adj[v].size()){
        while(st.size() && st.back()<=v) st.pop_back();
        if(st.size() && st.back()==v+1)
            dfs(v+1);
        else
            answ++, dfs(v+1); //adiciona
    }
    else{
        for(int j=adj[v].size()-1;j>=i;j--) st.push_back(adj[v][j]);
        if(adj[v][i]==v+1)
            dfs(v+1);
        else
            answ++, dfs(v+1); //adiciona
    }
}


int main(){
    fastio();
    int t;

    cin >> t;
    while(t--){
        cin >> n >> m;

        for(int i=0;i<=n;i++) adj[i].clear();

        for(int i=0;i<m;i++){
            int a, b;

            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(int i=0;i<=n;i++){
            sort(adj[i].begin(),adj[i].end());
        }

        answ = 0;
        dfs(1);
        cout << answ << "\n";
    }

    return 0;
}