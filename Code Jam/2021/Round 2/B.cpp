#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e3+5)
using namespace std;

const ll inf = 1e9;
ll dp[maxn][maxn];

ll solve(ll n, ll x, bool flag = true){
    //cout << n << " " << x << "\n";
    if(x==0)
        return (n==0) ? 0 : -inf;
    if(dp[n][x]!=-1)
        return dp[n][x];
    dp[n][x] = 0;
    for(ll i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(!flag||i>=3 &&(flag||n/i-1!=n-1))
                dp[n][x] = max(dp[n][x],solve(n/i-1,x-1,false));
            if(!flag||n/i>=3 &&(flag||i-1!=n-1))
                dp[n][x] = max(dp[n][x],solve(i-1,x-1,false));
        }   
    }
    return ++dp[n][x];
}

int main(){
    ll t, caso=0;
    memset(dp,-1,sizeof(dp));
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll answ = 0;
        for(int i=1;i<=n;i++)
            answ = max(answ,solve(n,i)+(i==1));
        cout << "Case #" << ++caso <<": "<< answ-1 << "\n";
    }


    return 0;
}