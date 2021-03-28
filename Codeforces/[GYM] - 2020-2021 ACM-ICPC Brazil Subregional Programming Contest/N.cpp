#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e3+5)
using namespace std;

vector<ll> sieve(ll n){
    vector<ll> lpf(n+1,1), primes;

    for(int i=2;i<=n;i++){
        if(lpf[i]!=1) continue;
        primes.push_back(i);
        for(int j=i;j<=n;j+=i)
            lpf[j] = i;
    }

    return primes;
}

vector<ll> adj[maxn];

int main(){
    ll n, m, k;
    vector<ll> primes = sieve(sqrt(1e15)+1), answ, arr;

    cin >> m >> n >> k;
    arr.assign(n,0);
    answ.assign(m,0);
    for(auto &x:arr)
        cin >> x;

    for(int i=0,x,y,w;i<k;i++){
        cin >> x >> y >> w;
        adj[x-1].push_back(y-1);
    }

    for(int i=0, ptr=0;i<m;i++){
        for(;ptr<primes.size() && arr[adj[i][0]]%primes[ptr];ptr++);
        answ[i] = ((ptr==primes.size()) ? arr[adj[i][0]] : primes[ptr]);
        for(auto j:adj[i])
            for(;arr[j]%answ[i]==0;arr[j]/=answ[i]);
    }

    for(auto x:answ)
        cout << x << " ";
    cout<<'\n';

    return 0;
}