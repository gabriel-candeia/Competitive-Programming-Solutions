#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e3+5)
using namespace std;

const ll mod = 1e9+7;
ll h, w, dp[maxn];
char a[maxn][maxn];

ll solve(){
    dp[1]= 1;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++){
            if(a[i-1][j]=='#')
                dp[j] = 0;
            if(a[i][j-1]=='.')
                dp[j] = (dp[j]+dp[j-1])%mod;
        }
    return dp[w];
}

int main(){
    cin >> h >> w;

    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            cin >> a[i][j];

    cout << solve() <<'\n';
    return 0;
}