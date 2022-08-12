#include<bits/stdc++.h>
#define maxn int(3e5+5)
#define maxm int(2)
#define ll long long
using namespace std;

vector<ll> arr;
ll dp[maxn][maxm];

ll _solve(int i, int j, int n){
    if(i==n)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j] = _solve(i+1,1,n)+arr[i];
    if(j==1)
        dp[i][j] = min(dp[i][j], _solve(i+1,0,n));
    return dp[i][j];
}

ll solve(int i, int j, int n){
    memset(dp,-1,sizeof(dp));
    return _solve(i,j,n);
}

int main(){
    int n;
    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    cout << min(solve(0,0,n),solve(0,1,n-1)+arr.back()) <<"\n";

    return 0;
}