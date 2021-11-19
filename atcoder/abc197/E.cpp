#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define ll long long
using namespace std;

const ll inf = 1e10;
vector<array<ll,2>> arr;
ll dp[maxn][2];

ll solve(int i, bool lst){
    if(i==arr.size())
        return 0;
    if(dp[i][lst]!=-1)
        return dp[i][lst];
    return dp[i][lst] = abs(arr[i][1]-arr[i][0]) + min(abs(arr[i-1][lst]-arr[i][0])+solve(i+1,1),abs(arr[i-1][lst]-arr[i][1])+solve(i+1,0));
}

int main(){
    int n;

    cin >> n;
    map<ll,array<ll,2>> mp;
    mp[0] = {0,0};
    mp[n+2] = {0,0};
    for(ll i=0, x, y;i<n;i++){
        cin >> x >> y;
        if(mp.find(y)==mp.end()){
            mp[y] = {x,x};
        }
        else{
            mp[y][0] = min(mp[y][0],x);
            mp[y][1] = max(mp[y][1],x);
        }
    }

    for(auto p:mp)
        arr.push_back(p.second);

    memset(dp,-1,sizeof(dp));
    cout << solve(1,0) << '\n';
    return 0;
}