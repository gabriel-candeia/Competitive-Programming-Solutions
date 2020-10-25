#include<bits/stdc++.h>
#define maxn 4005
#define ll long long
using namespace std;

ll dp[maxn][maxn], seen[maxn][maxn], n;
vector<ll> arr;
ll solve(ll i,ll k){
    if(i==2*n)
        return ((k) ? 1<<30: 0);
    if(seen[i][k])
        return dp[i][k];
    seen[i][k] = 1;
    int r1=1<<30, r2=1<<30;
    r2 = solve(i+1,k)-arr[i];
    if(k)
        r1 = solve(i+1,k-1)+(1000-arr[i])%1000;
    dp[i][k] = r1;
    if(abs(r2)<abs(r1))
        dp[i][k] = r2;
    return dp[i][k];
}

int main(){
    string s;

    cin >> n;
    arr.assign(2*n,0);
    for(int i=0;i<2*n;i++){
        cin >> s;
        int j = 0;
        arr[i] = (s[s.size()-1]-'0')+(s[s.size()-2]-'0')*10+(s[s.size()-3]-'0')*100;
    }
    memset(seen,0,sizeof(seen));
    printf("%.3f\n",abs(solve(0,n))/1000.0);
    return 0;
}