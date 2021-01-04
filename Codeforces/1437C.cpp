#include<bits/stdc++.h>
#define maxn 405
#define ll long long 
using namespace std;

ll n;
vector<ll> arr;
ll dp[maxn][maxn];

int solve(){
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
            dp[i][j] = (i) ? 1<<30 : 0;

    for(int i=0;i<n;i++){
        for(int j=1;j<maxn-1;j++){
            dp[i][j] = min(dp[i][j],dp[i][j-1]);
            dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j]+abs(arr[i]-j));
        }
    }

    ll answ = 1<<30;
    for(int j=1;j<maxn;j++)
        answ = min(answ,dp[n][j]);

    return answ;
}

int main(){
    int q;

    cin >> q;
    while(q--){
        cin >> n;
        arr.assign(n,0);
        for(int i=0;i<n;i++)
            cin >> arr[i];
        sort(arr.begin(),arr.end());

        cout << solve() << '\n';
    }

    return 0;
}