#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e6)
using namespace std;

int n, lim;
const ll inf = 1e17;
ll dp[maxn], cost[maxn], x;

int lsb(int x){
    return x&(-x);
}

int main(){
    cin >> n >> x;
    lim = (1<<n);
    for(int i=0;i<n;i++){
        cin >> cost[(1<<i)];
    }

    for(int msk=0;msk<lim;msk++){
        cost[msk] = cost[lsb(msk)] + cost[msk^lsb(msk)];
    }

    
    
    for(int msk=0;msk<lim;msk++){
        if(cost[msk]<=x){
            dp[msk] = cost[msk] = 1;
        }
        else{
            dp[msk] = cost[msk] = inf;
        }
    }

    for(int msk=0;msk<lim;msk++){
        for(int j=(msk-1)&msk;j;j = (j-1)&msk){
            dp[msk] = min(dp[msk],cost[j] + dp[msk^j]);
        }
    }

    cout << dp[lim-1] << "\n";

    return 0;
}