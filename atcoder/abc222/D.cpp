#include<bits/stdc++.h>
#define ll long long
#define maxn 3005
using namespace std;

const ll mod = 998244353;
ll dp[maxn][maxn];
int n;
vector<int> a, b;

//dp[i][j] é o numero de sequencias de tamanho i que terminam no elemento j e satisfazem todas as restrições

ll solve(){
    dp[0][0] = 1;
    for(int j=1;j<maxn;j++)
        dp[0][j] = (dp[0][j] + dp[0][j-1])%mod;

    for(int i=1;i<=n;i++){
        for(int j=a[i-1];j<=b[i-1];j++) 
            dp[i][j] = dp[i-1][j];
        for(int j=1;j<maxn;j++)
            dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
    }

    return dp[n][maxn-1];
}


int main(){
    cin >> n;
    a.assign(n,0), b.assign(n,0);
    for(auto &x:a)
        cin >> x;
    for(auto &x:b)
        cin >> x;
    

    cout << solve() <<"\n";

    return 0;
}