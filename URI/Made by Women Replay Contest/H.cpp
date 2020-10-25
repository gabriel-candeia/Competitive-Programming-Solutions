#include<bits/stdc++.h>
#define maxm 500
#define maxn 105   
#define ll long long
using namespace std;

ll dp[maxn][maxm][maxn], r[maxn], h[maxn], s, n;

ll solve(int i, int w, int k){
    if(w>s/2)
        return 0;
    if(i==n && k!=n)
        return 0;
    if(k==n)
        return dp[i][w][k] = w;
    if(dp[i][w][k]!=-1)
        return dp[i][w][k];
    dp[i][w][k] = max(solve(i+1,w,k), solve(i+1,w+r[i],k+1));
    dp[i][w][k] = max(dp[i][w][k], solve(i+1,w+h[i],k+1));
    return dp[i][w][k] = max(dp[i][w][k], solve(i+1,w+r[i]+h[i],k+2));
}

int main(){
    int t;
    cin >> t;
    while(t--){
        s=0;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> r[i];
            s+=r[i];
        }
        for(int i=0;i<n;i++){
            cin >> h[i];
            s+=h[i];
        }
        memset(dp,-1,sizeof(dp));
        cout << s-2*solve(0,0,0) << '\n';
    }

    return 0;
}