#include<bits/stdc++.h>
#define ll long long
#define maxn int(3e5+5)
#define maxm int(5e4)
using namespace std;

ll cost[2][maxn], dp[2][maxm], n, k, answ, tot;
vector<ll> arr;
const ll inf = 1e17;

void precomp(ll k, ll m){
    for(int i=0;i<maxm;i++)
        cost[k][i] = inf;

    cost[k][0] = 0;
    for(int i=1;i<m;i++)
        cost[k][0] += arr[i-1]-arr[i];

    for(int i=1;i+m-1<n;i++){
        if(m==1)
            cost[k][i] = 0;
        else if(m==2)
            cost[k][i] = arr[i]-arr[i+1];
        else
            cost[k][i] = cost[k][i-1] - (arr[i-1]-arr[i]) + (arr[i+m-2]-arr[i+m-1]);
    }
}
 
/*ll solve(ll i, ll qtd){
    if(i==k)
        return (qtd==0) ? 0 : inf;
    if(dp[i][qtd]!=-1)
        return dp[i][qtd];
    dp[i][qtd] = solve(i+1,qtd)+cost[0][i*(n/k)+tot-qtd];
    if(qtd)
        dp[i][qtd] = min(solve(i+1,qtd-1)+ cost[1][i*(n/k)+tot-qtd],dp[i][qtd]);
    return dp[i][qtd];
}*/

ll solve(){
    ll qtd = n%k;
    for(int i=0;i<maxm;i++)
        dp[k%2][i] = inf;
    dp[k%2][0] = 0;

    for(int i=k-1;i>=0;i--){
        ll curr = i%2, nxt = (i+1)%2;
        for(int i=0;i<maxm;i++)
            dp[curr][i] = inf;

        for(int j=0;j<=qtd;j++){
            dp[curr][j] = dp[nxt][j] + ((i*(n/k)+qtd-j<maxn) ? cost[0][i*(n/k)+qtd-j] : inf);
            if(j)
                dp[curr][j] = min(dp[curr][j],dp[nxt][j-1]+((i*(n/k)+qtd-j < maxn) ? cost[1][i*(n/k)+qtd-j] : inf));
        }
    }
    return dp[0][qtd];
}

int main(){
    
    cin >> n >> k; arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    sort(arr.rbegin(),arr.rend());
    precomp(0,n/k);
    precomp(1,n/k + (n%k!=0));
    
    tot = n%k;
    //memset(dp,-1,sizeof(dp));
    cout << solve() << '\n';
    return 0;
}