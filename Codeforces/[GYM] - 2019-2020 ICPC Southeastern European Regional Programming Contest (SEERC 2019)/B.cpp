#include<bits/stdc++.h>
#define ll long long
#define maxn 505
using namespace std;

const ll inf = 1e16;
ll dp[2][maxn][maxn], n, t[2][maxn], x[2][maxn], s1, s2;

ll solve(){
    for(int j=0;j<=s1;j++)
        for(int k=0;k<=s2;k++)
            dp[0][j][k] = dp[1][j][k] = inf;
    dp[0][0][0] = dp[1][0][0] = 0;

    for(int i=n-1;i>=0;i--){
        int curr = i%2, nxt = (i+1)%2;
        for(int j=0;j<=s1;j++){
            for(int k=0;k<=s2;k++){
                dp[curr][j][k] = dp[nxt][j][k];
                if(k){
                    ll k1 = max(k-x[1][i],0ll);
                    dp[curr][j][k] = min(dp[curr][j][k],dp[nxt][j][k1]+t[1][i]);
                }
                if(j){
                    ll j1 = max(j-x[0][i],0ll), k1 = max(k-max(x[0][i]-j,0ll),0ll);
                    dp[curr][j][k] = min(dp[curr][j][k],dp[nxt][j1][k1]+t[0][i]);
                }
            }
        }
    }

    return dp[0][s1][s2];
}

int main(){
    cin >> n >> s1 >> s2;

    vector<array<ll,4>> arr(n,array<ll,4>());
    for(int j=0;j<n;j++)
        for(int i=0;i<4;i++)
            cin >>  arr[j][i];
    
    sort(arr.begin(),arr.end());

    for(int j=0;j<n;j++){
        for(int i=0;i<2;i++){
            x[i][j] = arr[j][2*i];
            t[i][j] = arr[j][2*i+1];
        }
    }

    ll answ = solve();
    if(answ==inf)
        answ = -1;
    cout << answ << '\n';
    return 0;
}