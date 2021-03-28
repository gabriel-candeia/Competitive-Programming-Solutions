#include<bits/stdc++.h>
#define maxn 1005
#define maxm 200
using namespace std;


int x, y, dp[maxn][maxn];
string s;

int solve(int i, char last){
    if(i==s.size())
        return 0;
    if(dp[i][last]!=-1)
        return dp[i][last];
    if(s[i]=='?')
        return dp[i][last] = min(solve(i+1,'J')+x*(last=='C'),solve(i+1,'C')+y*(last=='J'));
    if(s[i]=='J')
        return dp[i][last] = solve(i+1,'J')+x*(last=='C');
    return dp[i][last] = solve(i+1,'C')+y*(last=='J');
}


int main(){
    int t, caso = 0;
    
    cin >> t;
    while(t--){
        cin >> x >> y >> s;
        memset(dp,-1,sizeof(dp));
        cout << "Case #" << ++caso << ": " << solve(0,' ') << '\n';
    }
    return 0;
}