#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e4+5)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

ll dp[maxn];
ll solve(ll wtmax, vector<ll> v, vector<ll> wt){
    int n = v.size();
    for(int i=0;i<=wtmax;i++)
        dp[i] = 0;

    for(int i=0;i<n;i++)
        for(int j=wtmax;j>=wt[i];j--)
            dp[j] = max(dp[j],dp[j-wt[i]]+v[i]);
    return dp[wtmax];
}

int main(){
    fastio();
    int n, m, p;

    cin >> n >> m >> p;

    vector<ll> wtC(n,0), vC(n,0);
    for(auto &x:wtC)
        cin >> x;

    vector<vector<ll>> wt(n+1,vector<ll>()), v(n+1,vector<ll>());

    for(int i=0;i<m;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        c--;
        wt[c].push_back(a);
        v[c].push_back(b);
    }

    for(int i=0;i<n;i++){
        vC[i] = solve(wtC[i],v[i],wt[i]);
    }

    cout << solve(p,vC,wtC) <<"\n";

    return 0;
}