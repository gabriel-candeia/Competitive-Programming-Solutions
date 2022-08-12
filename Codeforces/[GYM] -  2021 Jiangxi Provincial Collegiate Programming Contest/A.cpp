#include<bits/stdc++.h>
#define ll int
#define maxn 505
#define maxm 1005
using namespace std;

int n, m;
ll dp[2][maxn][maxm], mat[maxn][maxn];
const ll mod = 998244353;

//caminhos de (i,j) até (n-1,m-1) com extamente p 1s
void solve(){
    for(int i=n-1;i>=0;i--){
        int curr = i%2, nxt = 1-curr;
        for(int j=m-1;j>=0;j--){
            for(int p=maxm-1;p>=0;p--){
                dp[curr][j][p] = 0;
                if(i==n-1 && j==m-1){
                    dp[curr][j][p] = mat[i][j]==p;
                }
                else if(p-mat[i][j]>=0){
                    dp[curr][j][p] = (dp[curr][j][p] + dp[nxt][j][p-mat[i][j]])%mod;
                    if(j+1<maxn)
                        dp[curr][j][p] = (dp[curr][j][p] + dp[curr][j+1][p-mat[i][j]])%mod;
                }
            }
        }
    }
}

ll get(int l, int r){
    ll answ = 0;
    for(int i=max(l,0);i<=r && i<maxm;i++)
      answ = (answ + dp[0][0][i])%mod;
    return answ;
}

int main(){
    int p, q;
    cin >> n >> m;
    cin >> p >> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }

    // entre q, n+m-q;

    solve();
    cout << (get(q,n+m-1-p))<<"\n";

    return 0;
}
