#include<bits/stdc++.h>
#define ll long long
#define maxn 105
#define maxm int(1e5+5)
using namespace std;

const ll inf = 1e17;
ll dp[maxm], w[maxn], v[maxn], n, c;

ll solve(ll n){
    for(int j=1;j<maxm;j++)
        dp[j] = inf;

    for(int i=0;i<n;i++)
        for(int j=maxm-1;j>=v[i];j--)
            dp[j] = min(dp[j],dp[j-v[i]]+w[i]);
    
    for(int j=maxm-1;j>=0;j--)
        if(dp[j]<=c)
            return j;
}

int main(){
    cin >> n >> c;
    for(int i=0;i<n;i++)
        cin >> w[i] >> v[i];

    cout << solve(n) <<'\n';
    return 0;
}