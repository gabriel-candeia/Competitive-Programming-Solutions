#include<bits/stdc++.h>
#define ll long long
#define maxn int(5e3+5)
using namespace std;

const ll mod = 1e9+7;
ll dp[maxn][maxn], n, k, arr[maxn], cnt[maxn];
void precomp(){
    for(int i=0;i<n;i++)
        dp[0][i] = 1;

    for(int i=1;i<=k;i++){
        dp[i][0] = dp[i-1][1];
        dp[i][n-1] = dp[i-1][n-2];
        for(int j=1;j<n-1;j++)
            dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%mod;
    }

    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            if(j+1<n)
                cnt[j] = (cnt[j] + dp[i][j]*dp[k-i-1][j+1])%mod;
            if(j-1>=0)
                cnt[j] = (cnt[j] + dp[i][j]*dp[k-i-1][j-1])%mod;
        }
    }
    for(int j=0;j<n;j++)
        cnt[j]+=dp[k][j];
}


int main(){
    ll q, x, y, answ=0;
    cin >> n >> k >> q; 
    for(int i=0;i<n;i++)
        cin >> arr[i];

    precomp();
    for(int i=0;i<n;i++)
        answ = (answ + (cnt[i]*arr[i])%mod)%mod;

    for(int i=0;i<q;i++){
        cin >> x >> y; x--;
        answ = ((answ - (cnt[x]*arr[x])%mod)+mod)%mod;
        arr[x] = y;
        answ = (answ + (cnt[x]*arr[x])%mod)%mod;
        cout << answ <<'\n';
    }

    return 0;
}