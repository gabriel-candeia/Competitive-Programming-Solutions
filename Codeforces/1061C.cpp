#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;

vector<int> fatora(int n, int max){
    vector<int> h1, h2;
    for(int i=1;i*i<=n && i<=max;i++){
        if(n%i==0){
            h1.push_back(i);
            if(n!=i*i && n/i<=max) h2.push_back(n/i);
        }
    }
    h2.insert(h2.end(),h1.rbegin(),h1.rend());
    return h2;
}

int main(){
    int n;

    cin >> n;
    vector<ll> dp(n+1,0);
    dp[0] = 1;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        auto arr = fatora(x,n);
        for(auto y:arr){
            dp[y] = (dp[y]+dp[y-1])%mod;
        }
    }
    
    ll answ = 0;
    for(int i=1;i<=n;i++){
        answ = (answ+dp[i])%mod;
    }

    cout << answ <<"\n";

    return 0;
}