#include<bits/stdc++.h>
#define maxn 105
using namespace std;

int n, m;
vector<vector<pair<int,int>>> adj;
int memo[maxn][maxn][30];

int dp(int u, int v, int c){
    if(memo[u][v][c]!=-1)
        return memo[u][v][c];
    for(auto w:adj[u])
        if(w.second>=c && dp(v,w.first,w.second)==false)
            return memo[u][v][c] = true;
    return memo[u][v][c]=false;
}


int main(){
    memset(memo, -1 ,sizeof memo);

    cin >> n >> m;
    adj.assign(n+1,vector<pair<int,int>>());

    int x, y;
    char c;
    while(m--){
        cin >>  x >> y >> c;
        adj[x].push_back({y,c-'a'});
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << ((dp(i,j,0)==0) ? "B" : "A");
        }
        cout <<'\n';
    }
    
    return 0;
}