#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e6+5)
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector<vector<ll>> arr;
ll n, x, y, cnt=-1, dp[maxn][6];

ll solve(ll k, ll block){
    if(k==cnt) return 0;
    if(dp[k][block]!=-1) return dp[k][block];
    ll &answ = dp[k][block]; answ = 0;
    for(int i=0;i<arr[k].size();i++)
        for(int j=0;j<arr[k+1].size();j++)
            if(i!=block)
                answ = max(answ,abs(arr[k][i]-arr[k+1][j])+solve(k+1,(arr[k+1].size()==1) ? 5 : j));
    return answ;
}

int main(){
    fastio();
    vector<pair<ll,ll>> v;

    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> x >> y;
        v.push_back({x,y});
    }

    sort(v.begin(),v.end());
    for(ll i=0;i<n;i++){
        if(!i || v[i].first!=v[i-1].first){
            arr.push_back(vector<ll>());
            arr[++cnt].push_back(v[i].second);
        }
        else if(i==1 || v[i].first!=v[i-2].first)
            arr[cnt].push_back(v[i].second);
        else if(i==n-1 || v[i].first!=v[i+1].first)
            arr[cnt].push_back(v[i].second);
        else if(i==n-2 || v[i].first!=v[i+2].first)
            arr[cnt].push_back(v[i].second);
    }
    memset(dp,-1,sizeof(dp));
    cout << solve(0,5) <<'\n';

    return 0;
}