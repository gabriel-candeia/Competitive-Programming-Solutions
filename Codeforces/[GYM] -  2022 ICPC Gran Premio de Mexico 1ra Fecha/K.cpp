#include<bits/stdc++.h>
#define maxn int(5e5+5)
using namespace std;

int main(){
    int q, n;
    vector<int> a;
    cin >> q >> n;

    a.assign(n,0);
    for(auto &x:a)
        cin >> x;

    vector<int> dp(maxn,0);
    dp[0] = 1;

    for(int i=0;i<n;i++){
        for(int j=a[i];j<maxn;j++){
            dp[j] |= dp[j-a[i]];
        }
    }

    int last = 0;
    for(int j=maxn-1;j>=0;j--){
        if(dp[j]==1){
            dp[j] = 0;
            last = j;
        }
        else{
            dp[j] = last-j;
        }
    }

    for(int i=0;i<q;i++){
        int x;
        cin >> x;
         //assert(dp[x]>=0);
         cout << dp[x] <<"\n";
    }

    return 0;
}