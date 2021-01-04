#include<bits/stdc++.h>
#define maxn 105
#define maxm int(2e5+5)
#define ll long long
using namespace std;

const ll mod = 1e9+7;
ll dp[maxm], x[maxn], n, a, b;

ll solve(){
    dp[0] = 1;
    for(int i=0;i<n;i++)
        for(int j=maxm-1;j>=x[i];j--)
            dp[j] = (dp[j]+dp[j-x[i]])%mod;

    ll answ = 0;
    for(int j=a;j<=b;j++)
        answ = (answ+ dp[j])%mod;

    return answ;
}


int main(){
    cin >> n >> a >> b;
    for(int i=0;i<n;i++)
        cin >> x[i];
    
    cout << solve() << '\n';
    return 0;
}
