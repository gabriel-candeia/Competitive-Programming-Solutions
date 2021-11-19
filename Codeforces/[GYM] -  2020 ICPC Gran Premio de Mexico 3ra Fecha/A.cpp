#include<bits/stdc++.h>
#define maxn 105
#define maxm 1030
using namespace std;

int n, p;
vector<int> energia, d, s;
int dp[11][maxm][maxn], mochila[maxn][maxn][maxn];

int solveM(int i, int k, int cap){
    if(i>k)
        return 0;
    if(mochila[i][k][cap]!=-1)
        return mochila[i][k][cap];
    mochila[i][k][cap] = solveM(i+1,k,cap);
    if(cap>=d[i])
        mochila[i][k][cap] = max(mochila[i][k][cap], solveM(i+1,k,cap-d[i])+s[i]);
    return mochila[i][k][cap];
}

//no cara i, usando os caras msk e no problema j
int solve(int i, int msk, int j){
    if(i==n || j==p)
        return 0;
    if(dp[i][msk][j]!=-1)
        return dp[i][msk][j];
    dp[i][msk][j] = 0;
    for(int u=0;u<n;u++){
        if((msk&(1<<u)) == 0){
            for(int k=j;k<p;k++){
                dp[i][msk][j] = max(dp[i][msk][j], solve(i+1,msk|(1<<u),k+1) + solveM(j,k,energia[u]));
            }
        }
    }
    return dp[i][msk][j];
}

int main(){
    cin >> n >> p;
    energia.assign(n,0);
    d.assign(p,0);
    s.assign(p,0);

    for(auto &x:energia)
        cin >> x;
    for(auto &x:d)
        cin >> x;
    for(auto &x:s)
        cin >> x;
    
    energia.push_back(0);
    d.push_back(0);
    s.push_back(0);

    memset(mochila,-1,sizeof(mochila));
    memset(dp,-1,sizeof(dp));
    
    cout << solve(0,0,0) <<"\n";

    return 0;
}