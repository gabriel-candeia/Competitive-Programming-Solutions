#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

const ll mod = 998244353;
map<ll,vector<ll>> memo;
vector<ll> fatora(ll x){    
    if(memo.find(x)!=memo.end())
        return memo[x];
    auto &answ = memo[x];
    for(ll i=2;i*i<=x;i++){
        if((x%i)==0){
            answ.push_back(i);
            while((x%i)==0)
                x/=i;
        }
    }
    if(x!=1)
        answ.push_back(x);
    return answ;
}

ll calcula(ll x, ll y, ll m){
    ll answ = 0;
    auto fat = fatora(y/x);
    int siz = fat.size();
    
    for(int msk=0;(msk<(1<<siz));msk++){
        ll val = 1;
        for(int k=0;k<siz;k++)
            if((1<<k)&msk)
                val = val*fat[k];
        ll sinal = ((__builtin_popcount(msk)%2) ? -1 : 1);
        answ = answ + sinal*(m/(x*val));
    }
    return answ%mod;
}

int main(){ 
    //precomp();
    int t;
    cin >> t;

    while(t--){
        ll n, m;
        vector<ll> arr;

        cin >> n >> m;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        
        vector<ll> dp(n,0);
        dp[0] = 1;

        ll last = 1;
        for(int i=1;i<dp.size();i++){
            ll x = arr[i], y = arr[i-1];
            if(y%x) break;
            last = calcula(x,y,m)%mod;
            dp[i] = (dp[i-1]*last)%mod;
            assert(dp[i]>=0);
        }

        cout << dp[n-1] <<"\n";
        
    }

    return 0;
}