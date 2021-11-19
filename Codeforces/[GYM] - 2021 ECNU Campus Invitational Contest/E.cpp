#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

int n;
vector<int> adj[maxn];
int dfs(int u, int p, int t){
    if(u==t){
        return 1;
    }

    int answ = 0;
    for(auto v:adj[u]){
        if(v!=p){
            answ = dfs(v,u,t);
            if(answ!=0){
                return answ+1;
            }
        }
    }

    return 0;
}

int main(){
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int s, t;   
    cin >> s >> t;
    cout << (dfs(s,-1,t)%2==0 ? "Yes" : "No") <<"\n";

    return 0;
}