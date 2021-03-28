#include<bits/stdc++.h>
#define maxn 22
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int dp[(1<<maxn)];

int main(){
    fastio();
    int n;
    vector<int> arr;

    cin >> n;
    arr.assign(n,0);
    memset(dp,-1,sizeof(dp));
    for(auto &x:arr){
        cin >> x;
        dp[x] = x;
    }

    for(int i=0;i<maxn;i++)
        for(int mask=(1<<maxn);mask>=0;mask--)
            if(mask&(1<<i))
                dp[mask] = max(dp[mask],dp[mask^(1<<i)]);
    
    for(auto &x:arr){
        cout << dp[x^((1<<maxn)-1)] << ' ';
    }cout<<'\n';

    return 0;
}
/*
1011010
0100101
1+4+32
*/