#include<bits/stdc++.h>
#define maxn int(1e6+5)
#define maxm int(100+5)
#define ll long long
using namespace std;

ll dp[maxn], n, arr[maxm];

int main(){
    cin >> n;
    for(ll i=0;i<n;i++)
        cin >> arr[i];

    dp[0] = 1;
    for(ll i=0;i<n;i++)
        for(ll j=maxn;j>=arr[i];j--)
            dp[j] = max(dp[j],dp[j-arr[i]]);

    ll total = 0, last = 0, mx=0, answ=0;
    for(ll j=maxn-1;j>=0;j--)
        total += dp[j];

    for(ll i=0;i<n;i++)
        mx += arr[i];

    for(ll j=0;j<=mx;j++){
        if(dp[j]==1){
            answ += mx-j+1;
            total--;
        }
        else{
            answ += total;
        }
    }

    cout << answ <<'\n';
    return 0;
}