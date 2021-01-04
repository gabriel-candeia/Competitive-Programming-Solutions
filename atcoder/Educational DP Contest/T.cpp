#include<bits/stdc++.h>
#define ll long long
#define maxn int(3e4+5)
using namespace std;

const ll mod = 1e9+7;
ll dp[2][maxn], n;
string s;

ll solve(){
    dp[0][0] = 1;
    int curr, nxt;
    for(int i=0;i<s.size();i++){
        curr = i%2; nxt = 1-curr;
        for(int j=1;j<=(i+1);j++){
            dp[curr][j]=(dp[curr][j]+dp[curr][j-1])%mod;
            if(s[i]=='<')
                dp[nxt][j+1]=(dp[nxt][j+1]+dp[curr][j])%mod;
            else{
                dp[nxt][j+1]=((dp[nxt][j+1]-dp[curr][j])%mod+mod)%mod;
                dp[nxt][0]=(dp[nxt][0]+dp[curr][j])%mod;
            }
        }
        for(int j=0;j<=(i+1);j++)
            dp[curr][j]=0;
        
    }

    ll answ = 0;
    
    for(int j=1;j<=n;j++){
        dp[nxt][j]=(dp[nxt][j]+dp[nxt][j-1])%mod;
        answ=(answ+dp[nxt][j])%mod;
    }
    return answ;
}   
/*
se s[i]=='<' então
    dp[i][j] vai "afetar" dp[i+1][j+1]...dp[i+1][n]
se s[i]=='<' então
    dp[i+1][0]...dp[i+1][j-1]

se s[i-1]=='<' então 
    dp[i][j] = dp[i-1][1]+...+dp[i-1][j-1]+
se s[i-1]=='>' então 
    dp[i][j] = dp[i-1][j+1]+...+dp[i-1][n]

5 <<<<
1 1 


*/
int main(){
    cin >> n >> s;
    cout << solve() <<'\n';
    return 0;
}