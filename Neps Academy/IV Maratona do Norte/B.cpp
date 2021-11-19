#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
#define maxm 2
using namespace std;

int n;
const ll inf = 1e17;
ll dp[maxn][maxm], answ[maxn][maxm];
vector<pair<ll,ll>> arr;

ll solve(int i, bool ok){
    if(i>=n) return (ok) ? 0 : inf;
    if(dp[i][ok]!=-1) 
        return dp[i][ok];
    dp[i][ok] = max(abs(arr[i].first-arr[i+1].first),solve(i+2,ok));
    answ[i][ok] = answ[i+2][ok];
    if(ok==0){
        ll x = solve(i+1,1);
        if(x<dp[i][ok]){
            dp[i][ok] = x;
            answ[i][ok] = arr[i].second;
        }
    }
    return dp[i][ok];
}

int main(){
    
    cin >> n;
    arr.assign(n,{0,0});
    int cnt = 0;
    for(auto &x:arr)
        cin >> x.first, x.second = ++cnt;

    memset(answ,-1,sizeof(answ));
    memset(dp,-1,sizeof(dp));
    sort(arr.rbegin(),arr.rend());

    solve(0,0);
    int rem = answ[0][0];
    
    int last = -1;
    for(int i=0;i<arr.size();i++){
        if(arr[i].second==rem) continue;
        
        if(last==-1){
            last = arr[i].second;
        }
        else{
            cout << last << " " << arr[i].second <<"\n";
            last = -1;
        }
    }
    
    return 0;
}