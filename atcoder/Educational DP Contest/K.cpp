#include<bits/stdc++.h>
#define maxn 105
#define maxm int(1e5)+5
using namespace std;

int dp[maxm], a[maxn], n, k;

int solve(){
    for(int i=0;i<k;i++)
        for(int j=0;j<n && !dp[i] && i+a[j]<=k;j++)
            dp[i+a[j]] = 1;
    return dp[k];
}

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];

    cout << ((solve()) ? "First" : "Second") <<'\n';
    return 0;
}