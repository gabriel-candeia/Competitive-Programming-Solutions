#include<bits/stdc++.h>
#define maxn int(3005)
#define ll long long
using namespace std;

int n;
string s, t;
ll dp[maxn][maxn][2], x, y;
ll inf = 1e16;
ll solve(int i, int credit, bool block){
    if(i==n)
        return ((credit%2) ? inf : 0);
    if(dp[i][credit][block]!=-1)
        return dp[i][credit][block];
    if(s[i]==t[i])
        return dp[i][credit][block] = solve(i+1,credit,0);

    dp[i][credit][block] = solve(i+1,credit+1,1)+y;
    if(credit-block>0){
        dp[i][credit][block] = min(dp[i][credit][block],solve(i+1,credit-1,0));
    }
    if(i+1<n && s[i+1]!=t[i+1]){
        dp[i][credit][block] = min(dp[i][credit][block],solve(i+2,credit,0)+x);
    }
    return dp[i][credit][block];
}

int main(){
    int caso;
    cin >> caso;
    while(caso--){
        cin >> n >> x >> y;
        cin >> s >> t;

        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }

        int diff = 0;
        for(int i=0;i<n;i++){
            diff += (s[i]!=t[i]);
        }

        if(diff&1){
            cout << -1 <<"\n";
        }
        else{
            cout << solve(0,0,0) <<"\n";
        }
    }

    return 0;
}