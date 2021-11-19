#include<bits/stdc++.h>
#define maxn 1005
#define maxm int(3e5+5)
#define ll long long
using namespace std;


vector<pair<int,int>> adj[maxn];
vector<int> freq, seq;
const ll mod = 998244353;
ll dp[maxm];

bool dfs(int s, int p, int t){
    if(s==t)
        return 1;
    for(auto e:adj[s]){
        if(e.first!=p && dfs(e.first,s,t)){
            freq[e.second]++;
            return 1;
        }
    }
    return 0;
}

int main(){
    int n, m, k;

    cin >> n >> m >> k;
    freq.assign(n+1,0);

    seq.assign(m,0);
    for(auto &x:seq)    
        cin >> x;

    for(int i=0;i<n-1;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }

    for(int i=0;i<m-1;i++){
        dfs(seq[i],-1,seq[i+1]);
    }

    dp[0] = 1;

    ll soma = 0;
    for(int i=0;i<n-1;i++)
        soma += freq[i];

    for(int i=0;i<n-1;i++){
        for(int j=maxm-1;j>=freq[i];j--)
            dp[j] = (dp[j] + dp[j-freq[i]])%mod;
    }
    if((k+soma)%2==1 || (k+soma)<0){
        cout << 0 <<"\n";
    }
    else{
    cout << (dp[(k+soma)/2])%mod <<"\n";
    }
    return 0;
}