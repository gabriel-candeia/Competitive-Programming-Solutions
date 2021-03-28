#include<bits/stdc++.h>
#define ll long long
#define maxn ((1<<19))
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

const ll mod = 1e9+7;
ll dp[2][maxn], pwr[int(1e5)+5];
vector<ll> primes;

ll ehprimo(ll y){
    for(int i=2;i*i<=y;i++)
        if(y%i==0)
            return false;
    return true;
}

void precomp(){
    for(int i=2;i<=70;i++)
        if(ehprimo(i))
            primes.push_back(i);
    
    pwr[0] = 1;
    for(int i=1;i<=int(1e5);i++)
        pwr[i] = (pwr[i-1]*2)%mod;
}

ll f(ll x){
    ll answ = 0;
    for(int i=0;i<primes.size();i++){
        ll qtd = 0;
        while(x%primes[i]==0){
            x/=primes[i];
            qtd++;
        }
        answ ^= ((qtd%2)<<i);
    }
    return answ;
}

int main(){
    fastio();
    ll n, x;
    map<ll,ll> mp;
    vector<pair<ll,ll>> arr;
    cin >> n;
    
    precomp();
    for(int i=0;i<n;i++){
        cin >> x;
        mp[f(x)]++;
    }   

    for(auto p:mp)
        arr.push_back(p);

    dp[0][0] = 1;
    ll curr = 1, nxt = 0;
    
    for(auto p:arr){
        curr = 1-curr; nxt = 1-curr;
        for(int i=0;i<maxn;i++)
            dp[nxt][i] = 0;

        for(int i=0;i<maxn;i++){
            dp[nxt][i^p.first] = (dp[nxt][i^p.first] + (dp[curr][i]*pwr[p.second-1])%mod)%mod;
            dp[nxt][i] = (dp[nxt][i]+(dp[curr][i]*pwr[p.second-1])%mod)%mod;
        }
    }
    
    cout << (dp[nxt][0]-1+mod)%mod <<'\n';
    return 0;
}