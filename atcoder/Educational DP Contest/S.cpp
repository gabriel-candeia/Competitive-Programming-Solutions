#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
using namespace std;

ll n, d, dp[maxn][2][105];
const ll mod = 1e9+7;
string s;

ll solve(int i, bool block, int val){
    if(i==n)
        return (val==0);
    if(dp[i][block][val]!=-1)
        return dp[i][block][val];
    dp[i][block][val] = 0;
    for(int j='0';j<='9';j++){
        if(!block || (block && j<=s[i])){
            dp[i][block][val] = (dp[i][block][val]+solve(i+1,(block && j==s[i]),(val+j-'0')%d))%mod;
        }
    }
    return dp[i][block][val];
}

int main(){
    cin >> s >> d;

    n = s.size();
    memset(dp,-1,sizeof(dp));

    cout << (solve(0,true,0)-1+mod)%mod <<'\n';
    return 0;
}