#include<bits/stdc++.h>
#define M 105
#define N 100005
#define ll long long
using namespace std;

const ll mod = 1e9+7;
ll dp[N][M], arr[N];

int main(){
    int n, m;

    /*
        dp[i][j] counts the number of such sequences (where adjacent elements differ at most 1 and
        every element is a integer in [1,m]) with i elements ended with j.
    */    

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            dp[i][j] = 0;
        }
    }
    if(arr[0]){
        dp[0][arr[0]] = 1;
    }
    else{
        for(int j=1;j<=m;j++){
            dp[0][j] = 1;
        }
    }

    for(int i=1;i<n;i++){
        if(arr[i]){
            dp[i][arr[i]] = (dp[i-1][arr[i]] + dp[i-1][arr[i]-1]+dp[i-1][arr[i]+1])%mod;
        }
        else{
            for(int j=1;j<=m;j++){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]+dp[i-1][j+1])%mod;
            }
        }
    }

    ll answ=0;
    for(int j=1;j<=m;j++){
        answ+=dp[n-1][j];
        answ%=mod;
    }

    cout << answ << '\n';
    return 0;
}

