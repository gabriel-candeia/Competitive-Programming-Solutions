#include<bits/stdc++.h>
#define ld long double
#define maxn int(1e5+5)
using namespace std;

vector<int> adj[maxn];

ld solve(int u, int p){
    if(adj[u].size()==1 && p!=-1)
        return 0;
    ld answ = 0;
    ld prob = (p==-1) ? 1.0/adj[u].size() : 1.0/((int)adj[u].size() -1);
    for(auto v:adj[u]){
        if(v!=p)
            answ += solve(v,u);
    }
    return answ*(prob)+1;
}

int main(){
    int n;

    cin >> n;
    if(n==1){
        cout << 0 <<"\n";
        return 0;
    }

    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << fixed << setprecision(16) << solve(1,-1) <<"\n";


    return 0;
}