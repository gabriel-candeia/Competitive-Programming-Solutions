#include<bits/stdc++.h>
#define ll long long
#define maxn int(5e3+1)
using namespace std;

vector<pair<ll,ll>> range;
ll dp[2][2*maxn], arr[2*maxn], n, x, cnt;
const ll inf = 1e17;

ll solve(){
    
    for(int i=0;i<cnt;i++)
        dp[0][i] = inf;
    dp[0][x] = 0;
    
    for(int i=0;i<n;i++){
        
        int curr = i%2, nxt = 1-curr;

        for(int j=0;j<cnt;j++) 
            dp[nxt][j] = inf;

        for(int j=cnt-2;j>=0;j--)
            dp[curr][j] = min(dp[curr][j],dp[curr][j+1] + abs(arr[j+1]-arr[j]));

        for(int j=1;j<cnt;j++)
            dp[curr][j] = min(dp[curr][j],dp[curr][j-1] + abs(arr[j]-arr[j-1]));

        for(int j=0;j<cnt;j++){
            if(j<range[i].first || j>range[i].second)
                dp[nxt][j] = min(dp[nxt][j],dp[curr][j]+min(abs(arr[range[i].first]-arr[j]),abs(arr[j]-arr[range[i].second])));
            else
                dp[nxt][j] = min(dp[nxt][j],dp[curr][j]);
        }
    }
    
    ll answ = inf;
    for(int i=0;i<cnt;i++){
        answ = min(answ,dp[n%2][i]);
    }

    return answ;
}

int main(){
    ll a, b;
    map<ll,ll> compress;

    cin >> n >> x;
    compress[x];
    for(int i=0;i<n;i++){
        cin >> a >> b;
        range.push_back({a,b});
        compress[a]; compress[b];
    }

    cnt = 0;
    for(auto &p : compress){
        p.second = cnt++;
        arr[p.second] = p.first;
    }
    
    for(auto &p:range){
        p.first = compress[p.first];
        p.second = compress[p.second];
    }
    x = compress[x];

    cout << solve() <<'\n';
    
    return 0;
}