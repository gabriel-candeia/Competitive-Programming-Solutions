#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ll long long
#define maxn 101
using namespace std;

const ll MOD = 998244353;
vector<ll> arr;
ll dp[maxn][maxn][maxn];


ll solve(int i, int tam, int val, int mod){
    if(tam==0)
        return (val==0);
    if(i==arr.size() || tam<0)
        return 0;
    if(dp[i][tam][val]!=-1)
        return dp[i][tam][val];
    
    return dp[i][tam][val] = (solve(i+1,tam,val, mod) + solve(i+1,tam-1,(val+arr[i])%mod,mod))%MOD;
}

int main(){
    fastio();
    int n;
    cin >> n;
    arr.assign(n,0);

    for(auto &x:arr)
        cin >> x;

    ll answ = 0;
    for(int i=1;i<=n;i++){
        memset(dp,-1,sizeof(dp));
        answ = (answ + solve(0,i,0,i))%MOD;
    }

    cout << answ <<"\n";

    return 0;
}