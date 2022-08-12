#include<bits/stdc++.h>
#define maxn int(5005)
#define ll long long
using namespace std;

int n, m, k;
const ll inf = 1e17;
ll dp[maxn][maxn], best[maxn], a[maxn], b[maxn], c[maxn];
vector<int> adj[maxn];

ll solve(int i, int army){
    if(i==n){
        return ((army>=0) ? 0 : -inf);
    }
    if(army<a[i]){
        return -inf;
    }
    if(dp[i][army]!=-1){
        return dp[i][army];
    }
    dp[i][army] = solve(i+1,army+b[i]);
    for(ll j=0, acm=0;j<adj[i].size();j++){
        acm += adj[i][j];
        ll x = solve(i+1,army+b[i]-j-1);
        if(x>=0){
            dp[i][army] = max(dp[i][army],acm + x);
        }
    }
    return dp[i][army];
}

int main(){
    cin >> n >> m >> k;
    for(int i=0;i<=n;i++) best[i] = i;

    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    for(int i=0;i<m;i++){
        ll x, y;
        cin >> x >> y;
        x--, y--;
        best[y] = max(best[y],x);
    }

    for(int i=0;i<n;i++){
        adj[best[i]].push_back(c[i]);
    }

    for(int i=0;i<n;i++){
        sort(adj[i].rbegin(),adj[i].rend());
    }

    memset(dp,-1,sizeof(dp));
    ll answ = solve(0,k);
    if(answ<0) answ = -1;
    cout << answ <<"\n";
    return 0;
}