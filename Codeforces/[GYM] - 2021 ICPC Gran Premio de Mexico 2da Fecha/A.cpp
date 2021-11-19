#include<bits/stdc++.h>
#define maxn 20
#define maxm int(1e6+5)
#define ll long long
using namespace std;

const ll mod = 998244353;
vector<pair<int,int>> edges;

int countEdges(int msk){
    int answ = 0;
    for(auto e:edges)
        if((msk&(1<<e.first)) && (msk&(1<<e.second)))
            answ++;
    return answ;
}

ll binpow(ll a, ll b){
    ll result = 1;
    while(b){
        if(b&1)
            result = (a*result)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return result;
}

int lsb(int x){
    return (x&(-x));
}

ll dp[maxn][maxm];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        edges.push_back({a-1,b-1});
    }

    for(int msk=0;msk < (1<<n);msk++){
        for(int i=n;i>1;i--){
            for(int j=(msk-1)&msk;j;j=(j-1)&msk)
                if(j&lsb(msk))
                    dp[i][msk] = (dp[i][msk] + dp[1][j]*dp[i-1][msk^j])%mod;
        }
        dp[1][msk] = binpow(2,countEdges(msk));
        for(int i=n;i>1;i--)
            dp[1][msk] = ((dp[1][msk] - dp[i][msk])%mod + mod)%mod;
    }
    
    
    for(int k=1;k<=n;k++){
        cout << dp[k][(1<<n)-1] << "\n";
    }

    return 0;   
}