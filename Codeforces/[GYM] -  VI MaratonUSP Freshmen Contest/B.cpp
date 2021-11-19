#include<bits/stdc++.h>
#define maxn int(1e3+5)
using namespace std;

int dp[maxn][maxn];
string s, t;
int solve(int i, int j){
    if(i==s.size() || j==t.size())
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    return dp[i][j] = max({solve(i+1,j+1)+(s[i]==t[j]),solve(i+1,j),solve(i,j+1)});
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin >> s >> t;
    cout << solve(0,0) <<"\n";
    return 0;
}