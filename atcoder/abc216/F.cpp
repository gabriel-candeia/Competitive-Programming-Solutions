#include<bits/stdc++.h>
#define ll long long
#define maxn 5005
using namespace std;

int n;
const ll mod = 998244353;
vector<ll> a, b;
vector<pair<ll,ll>> c;
ll dp[2][maxn][maxn];
void solve(int k){
    dp[k][0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<maxn;j++){
            dp[k][i+1][j] = (dp[k][i+1][j]+dp[k][i][j])%mod;
            if(j+b[i]<maxn){
                dp[k][i+1][j+b[i]] = (dp[k][i+1][j+b[i]]+dp[k][i][j])%mod;
            }
        }
    }
}

int main(){
    cin >> n;
    a.assign(n,0);
    b.assign(n,0);
    c.assign(n,{0,0});

    for(auto &x:c)
        cin >> x.first;
    for(auto &x:c)
        cin >> x.second;

    sort(c.begin(),c.end());
    for(int i=0;i<n;i++){
        a[i] = c[i].first;
        b[i] = c[i].second;
    }

    for(int k=0;k<2;k++){
        solve(k);
        reverse(b.begin(),b.end());
    }

    for(int i=0;i<n;i++){
        for(int j=1;j<maxn;j++){
            dp[1][i][j] = (dp[1][i][j]+dp[1][i][j-1])%mod;
        }
    }

    for(int i=0;i<n;i++){
        a[i]-=b[i];
    }
    
    ll answ = 0;
    /*if(n!=1 && a[0]>=0)
        answ = dp[1][n-1][a[0]];*/
    
    for(int i=0;i<n;i++){
        //combinar a linha i-1 de dp[0] com a linha n-i-2 de dp[1]
        int l0 = i-1, l1 = n-i-2;
        l0++; l1++;
        for(int j=0;j<=a[i];j++){
            answ = (answ + dp[0][l0][j]*1)%mod;
        }
    }
    /*for(int j=0;j<=a[n-1];j++){
        answ = (answ+dp[0][n-1][j])%mod;
    }*/

    cout << answ << "\n";

    return 0;
}