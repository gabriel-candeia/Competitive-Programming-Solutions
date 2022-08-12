#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define maxn int(3e5+5)
using namespace std;

int cnt = 1;
int n, m;
vector<int> adj[maxn], colors[maxn];
int used[maxn], answ[maxn];
set<int> st;

void solve(int u, int p){
    vector<int> check;

    for(auto c:colors[u]){
        if(answ[c]) used[answ[c]] = 1;
        else check.push_back(c);
    }

    //Percorre no maximo 2*colors[u].size();
    int proxCor = 1;
    for(auto c:check){
        while(used[proxCor]==1) proxCor++;
        answ[c] = proxCor++;
    }

    for(auto c:colors[u]){
        used[answ[c]] = 0;
    }

    for(auto v:adj[u]){
        if(v!=p){
            solve(v,u);
        }
    }
}

int main(){
    fastio();    
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int qtd, color;
        cin >> qtd;
        for(int j=0;j<qtd;j++){
            cin >> color;
            colors[i].push_back(color);
        }
    }

    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
    }
    
    solve(1,-1);

    int mx = 1;
    for(int i=1;i<=m;i++){
        if(answ[i]==0) answ[i] = 1;
        mx = max(mx,answ[i]);
    }

    cout << mx << "\n";
    for(int i=1;i<=m;i++){
        cout << answ[i] << " ";
    }cout<<"\n";

    return 0;
}