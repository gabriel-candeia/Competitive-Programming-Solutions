#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9+7;

int solve(int n){
    vector<ll> cnt(n+1,0);
    cnt[0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=6;j++){
            if(j<=i){
                cnt[i] = (cnt[i] + cnt[i-j])%mod;
            }
        }
    }

    return cnt[n];
}

int main(){
    int n;

    cin >> n;

    cout << solve(n) << '\n';

    return 0;
}