#include<bits/stdc++.h>
#define maxn 100
#define maxm int((1<<18)+5)
using namespace std;

const int inf = 10000;
int n, m, adj[maxn], dp[maxm];

int cnt(int x){
    int answ = 0;
    for(;x;x/=2)
        answ += x%2;
    return answ;
}

int main(){
    int x, y;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> x >> y; x--; y--;
        adj[x] |= 1<<y;
        adj[y] |= 1<<x;
    }

    for(int j=1;j<(1<<n);j++)
        dp[j] = inf;
    
    dp[0] = 1;
    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<n);j++)
            if(dp[j]==1 && ((adj[i]&j)==j))
                dp[j|(1<<i)] = 1;

    for(int i=1;i<(1<<n);i++)
        for(int j=i;(--j)&=i;)
            dp[i] = min(dp[i],dp[j]+dp[i^j]);

    cout << dp[(1<<n)-1] <<'\n';

    return 0;
}