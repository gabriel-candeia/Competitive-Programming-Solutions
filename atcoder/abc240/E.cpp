#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

int tempo=1;
vector<int> adj[maxn];
vector<pair<int,int>> answ;

void solve(int u, int p){
    answ[u].first = tempo;
    //cout << u << " " << p << "\n";
    bool take = true;
    for(auto v:adj[u]){
        if(v!=p){
            tempo += (1-take);
            take = false;
            solve(v,u);
        }
    }

    answ[u].second = tempo;
}

int main(){
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    answ.assign(n+1,{0,0});
    solve(1,-1);

    for(int i=1;i<=n;i++){
        cout << answ[i].first << " " << answ[i].second <<"\n";
    }

    return 0;
}