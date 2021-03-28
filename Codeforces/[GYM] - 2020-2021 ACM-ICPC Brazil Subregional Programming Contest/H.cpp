#include<bits/stdc++.h>
#define ll long long
#define maxn 55
using namespace std;

ll a, b, n, k;
vector<ll> arr;

ll dp[maxn][maxn];
ll comb(ll n, ll k){
    if(n<k || k<0)
        return 0;
    if(k==0)
        return dp[n][k] = 1;
    if(k==1)
        return dp[n][k] = n;
    if(dp[n][k]!=-1)
        return dp[n][k];
    return dp[n][k] = comb(n-1,min(k,n-1-k))+comb(n-1,min(k-1,n-k));
}   

ll teste(ll x, ll k){
    ll answ = 0;
    for(int i=0;i<n && k;i++){
        if(arr[i]>x) continue;
        answ += comb(n-i-1,min(k,n-i-1-k));
        x-=arr[i], k--;
    }
    return answ + (k==0);
}

int main(){
    memset(dp,-1,sizeof(dp));
    
    cin >> n >> k; 
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;
    sort(arr.rbegin(),arr.rend());
    cin >> a >> b;

    cout << teste(b, k) - teste(a-1, k)<< '\n';

    return 0;
}