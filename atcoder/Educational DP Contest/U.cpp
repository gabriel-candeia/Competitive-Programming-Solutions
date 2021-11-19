#include<bits/stdc++.h>
#define maxn int(7e4+5)
#define maxm int(16+1)
#define ll long long
using namespace std;

int n;
ll cost[maxn], dp[maxn], mat[maxm][maxm];

ll calc(int msk){
    ll answ = 0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if((msk&(1<<i))&&(msk&(1<<j)))
                answ += mat[i][j];
    return answ;
}

int main(){
    cin >> n;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> mat[i][j];
    
    for(int i=0;i<(1<<n);i++)
        cost[i] = calc(i);
    
    for(int i=0;i<(1<<n);i++){
        dp[i] = cost[i];
        for(int j=(i-1)&i;j;j = (j-1)&i){
            dp[i] = max(dp[i],cost[i^j]+dp[j]);
        }
    }
    
    cout << dp[(1<<n)-1] << "\n";

    return 0;
}