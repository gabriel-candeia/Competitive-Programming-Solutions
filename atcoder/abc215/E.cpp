#include<bits/stdc++.h>
#define ll long long
#define maxn 1025
using namespace std;

const ll mod = 998244353;
int n;
ll dp[maxn][11][maxn];
string s;

ll solve(int i, int last, int j){
    if(i==n)
        return 1;
    if(dp[i][last][j]!=-1)
        return dp[i][last][j];
    dp[i][last][j] = 0;
    if(s[i]-'A'==last){
        dp[i][last][j] = (2*solve(i+1,last,j))%mod;
    }
    else{
        dp[i][last][j] = (dp[i][last][j] + solve(i+1,last,j))%mod;
        if((j&(1<<(s[i]-'A')))==0)
            dp[i][last][j] = (dp[i][last][j] + solve(i+1,s[i]-'A',(j|(1<<(s[i]-'A')))) )%mod;
    }
    return dp[i][last][j];
}

int main(){

    cin >> n >> s;
    s.push_back('k');
    memset(dp,-1,sizeof(dp));
    cout << ((solve(0,10,0)-1+mod)%mod) << "\n";

    return 0;
}