#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e3+5)
using namespace std;

#define INF 1e18

ll dp[maxn], arr[maxn], n, d, c;

int main(){
    cin >> n >> d >> c;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<maxn;i++)
        dp[i] = INF;
    dp[0] = 0;
    
    for(int i=1;i<=n;i++){
        ll val = d;
        for(int j=i;j>0;j--){
            
            val = val + (arr[i]-arr[j])*c;
            
         
            dp[i] = min(dp[i],val+dp[j-1]);
        }
    }

    cout << dp[n] <<'\n';

    return 0;
}