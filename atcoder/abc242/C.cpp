    #include<bits/stdc++.h>
    #define ll long long
    #define maxm 11
    using namespace std;

    const ll mod = 998244353;
    ll dp[2][maxm];
    int n;

    void solve(){
        for(int i=n-1;i>=0;i--){
            int cur = (i%2), lst = (i+1)%2;
            for(int j=1;j<10;j++){
                if(i==n-1) dp[cur][j] = 1;
                else dp[cur][j] = (dp[lst][j] + dp[lst][j-1] + dp[lst][j+1])%mod;
            }
        }
    }

    int main(){
        cin >> n;
        solve();
        ll answ = 0;
        for(int i=1;i<=9;i++)
            answ = (answ + dp[0][i])%mod;
        cout << answ <<"\n";
        return 0;
    }