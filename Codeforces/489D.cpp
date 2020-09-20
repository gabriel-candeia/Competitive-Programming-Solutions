#include<bits/stdc++.h>
#define maxn 3001
#define ll long long
using namespace std;

ll mat[maxn][maxn];

int main(){
    ll n, m, answ=0, x, y;
    vector<vector<ll>> adj;

    cin >> n >> m;
    adj.assign(n+1,vector<ll>());
    for(int i=0;i<m;i++){
        cin >> x >> y;
        adj[x].push_back(y);
    }

    for(int i=1;i<=n;i++)
        for(auto v:adj[i])
            for(auto u:adj[v])
                mat[i][u]++;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
                answ += mat[i][j]*(mat[i][j]-1)/2;
        
    cout << answ <<'\n';

    return 0;
}