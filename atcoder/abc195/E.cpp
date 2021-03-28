#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

int dp[maxn][7], n;
string s, t;
int solve(int i, int x){
    if(i==n)
        return dp[i][x] = (x==0);
    if(dp[i][x]!=-1)
        return dp[i][x];
    if(s[i]=='A')
        dp[i][x] = !(solve(i+1,(10*x)%7)==0 || solve(i+1,(10*x+t[i]-'0')%7)==0);
    else
        dp[i][x] = (solve(i+1,(10*x)%7)==1 || solve(i+1,(10*x+t[i]-'0')%7)==1);
    return dp[i][x];
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin >> n >> t >> s;
    
    cout << (solve(0,0) ? "Takahashi" : "Aoki") << "\n";

    return 0;
}