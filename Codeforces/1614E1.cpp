#include<bits/stdc++.h>
#define ll long long
#define maxn int(5e6+5)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

ll freq[maxn], dp[maxn], cnt[maxn];

int main(){
    fastio();
    int n;
    
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    
    for(int i=1;i<maxn;i++){
        for(int j=i;j<maxn;j+=i){
            freq[i] += cnt[j];
        }
    }
    
    dp[1] = freq[1];
    ll answ = 0;
    for(int i=1;i<maxn;i++){
        for(int j=2*i;j<maxn;j+=i){
            dp[j] = max(dp[j],dp[i] + (j-i)*freq[j]);
        }
        answ = max(answ,dp[i]);
    }

    cout << answ <<"\n";

    return 0;
}