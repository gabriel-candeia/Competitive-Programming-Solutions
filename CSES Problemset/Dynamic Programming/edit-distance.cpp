#include<bits/stdc++.h>
#define N 5005
using namespace std;

string s, t;
int n, m;
int dp[N][N];

/*
    dp[i][j] is the edit distance of s[i...n] and t[j...m]. Notice that:

    if (s[i]==t[j]):
        dp[i][j] == dp[i-1][j-1])
    else:
        dp[i][j] == min(dp[i-1][j-1]+1,dp)


*/

int main(){
    cin >> s >> t;
    n = s.size(); m = t.size();

    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            dp[i][j] = 0;
        }
    }

    for(int i=0;i<=n;i++){
        dp[i][m] = n-i;
        
    }

    for(int j=0;j<=m;j++){
        dp[n][j] = m-j;
    }

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(s[i]==t[j]){
                dp[i][j] = dp[i+1][j+1];
            }
            else{
                dp[i][j] = min({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]})+1;
            }
        }
    }

    cout << dp[0][0] << '\n';

    return 0;
}