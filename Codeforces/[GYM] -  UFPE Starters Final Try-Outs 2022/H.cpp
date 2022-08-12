#include<bits/stdc++.h>
#define maxn 15
#define maxm 1<<14
#define maxk 101
#define ll long long
using namespace std;

int n, k;
const ll mod = 1e9+7;
ll dp[maxn][maxm][maxk];

ll solve(int i, int msk, int soma){
    if(soma<0 || soma>k)
        return 0;
    if(i==n)
        return soma==k;
    if(dp[i][msk][soma]!=-1)
        return dp[i][msk][soma];
    auto &ret = dp[i][msk][soma];
    ret = 0;
    for(int pos = 0;pos<n;pos++){
        if((msk&(1<<pos))==0){
            ret = (ret + solve(i+1,msk|(1<<pos),soma + abs(pos-i)))%mod;
        }
    }
    return ret;
}

int main(){
    cin >> n >> k;

    memset(dp,-1,sizeof(dp));
    cout << solve(0,0,0) <<"\n";
    return 0;
}