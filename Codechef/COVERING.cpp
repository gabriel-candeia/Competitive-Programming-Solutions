#include<bits/stdc++.h>
#define ll long long
#define maxn 20
using namespace std;

const ll mod = 1e9+7;
ll f[1<<maxn], g[1<<maxn], h[1<<maxn], dp[1<<maxn];

int main(){
    ll n;

    cin >> n;
    for(int i=0;i<(1<<n);i++)
        cin >> f[i];
    
    for(int i=0;i<(1<<n);i++)
        cin >> g[i];

    for(int i=0;i<(1<<n);i++)
        cin >> h[i];
    //dp[i][mask] = dp[i-1][mask]
    ////dp[i][mask] = dp[i-1][mask^(1<<i)]+dp[i-1][mask]
    
    /*for(int mask=0;mask<(1<<maxn);mask++){
        for(int j=mask-1;j;j=(j-1)&mask)
            dp[mask] = (dp[mask] + f[j]*g[mask^j])%mod;
        dp[mask] = (dp[mask] + f[0]*g[mask])%mod;
    }

    for(int mask=0;mask<(1<<maxn);mask++){
        f[0] = 0, g[0] = 0;
        for(int j=mask-1;j;j=(j-1)&mask)
            f[mask] = (f[mask] + dp[j]*h[mask^j])%mod;
        f[mask] = (dp[mask] + dp[0]*h[mask])%mod;
    }

    for(int i=0;i<maxn;i++)
        for(int mask=0;mask<(1<<maxn);mask++)
            if(mask&(1<<i))
                f[mask] = (f[mask]+f[mask^(1<<i)])%mod;*/

    ll answ = 0;
    for(int mask=0;mask<(1<<maxn);mask++)
        answ = (answ + f[mask])%mod;

    ll sum = 0;
    for(int x=(1<<n)-1;x<(1<<n);x++)
        for(int mask=0;mask<(1<<n);mask++)
            for(int mask1=0;mask1<(1<<n);mask1++)
                for(int mask2=0;mask2<(1<<n);mask2++)
                    if(((mask|mask1|mask2)&x)==x)
                        sum = (sum+f[mask]*g[mask1]*h[mask2])%mod;

    cout << f[(1<<n)-1] <<" "<< sum << "\n";
    cout << answ << '\n';
    
    return 0;
}