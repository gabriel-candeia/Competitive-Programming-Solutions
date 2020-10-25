#include<bits/stdc++.h>
#define maxn int(3e3+5)
#define ll long long
using namespace std;

ll n, a[maxn], dp[maxn];

ll solve(){
    int turno = n%2;
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            if((j-i+1)%2==turno)
                dp[j] = max(dp[j-1]+a[j],dp[j]+a[i]);
            else
                dp[j] = min(dp[j-1]-a[j],dp[j]-a[i]);
        }
    }

    return dp[n];
}


int main(){
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];

    cout << solve() <<'\n';
    return 0;
}