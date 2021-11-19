#include<bits/stdc++.h>
#define ll long long
#define maxn 405
using namespace std;

const ll mod = 998244353ll;
ll dp[maxn][maxn];
ll vis[maxn][maxn];
ll comb[maxn][maxn];
vector<int> adj[maxn];

ll solve(int i, int j){
    if(j<i){
        return 1;
    }
    if(vis[i][j]){
        return dp[i][j];
    }
    vis[i][j] = 1;
    dp[i][j] = 0;
    for(auto x:adj[i]){
        if(x>j) continue;
        if((x-i+1)%2==0 && (j-(x+1)+1)%2==0){
            int left = (x-i+1)/2, right = (j-(x+1)+1)/2;
            dp[i][j] = (dp[i][j] + ((( solve(i+1,x-1)*solve(x+1,j) )%mod)*(1ll)*comb[right+left][left])%mod)%mod;
        }
    }
    return dp[i][j];
}

int main(){

    for(int i=0;i<maxn;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || j==i){
                comb[i][j] = 1;
            }
            else{
                comb[i][j] = (comb[i-1][j]+comb[i-1][j-1])%mod;
            }
        }
    }
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    cout << solve(1,2*n) << "\n";
    return 0;
}
