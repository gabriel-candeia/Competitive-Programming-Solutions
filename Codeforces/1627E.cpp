#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)

#define maxn int(1e5+5)
using namespace std;

const ll inf = 1e17;


int main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        vector<int> loss;
        vector<vector<array<int,4>>> arr;
        vector<map<int,ll>> dp;

        cin >> n >> m >> k;

        arr.assign(n+1,vector<array<int,4>>());
        dp.assign(n+1,map<int,ll>());
        loss.assign(n+1,0);
        for(int i=1;i<=n;i++)
            cin >> loss[i];

        for(int i=0;i<k;i++){
            int a, b, c, d, h;
            cin >> a >> b >> c >> d >> h;
            arr[a].push_back(array<int,4>{b,c,d,h});
            dp[a][b] = inf;
            dp[c][d] = inf;
        }

        dp[1][1] = 0;
        dp[n][m] = inf;

        for(int i=1;i<=n;i++){
            vector<ll> pos;
            vector<ll>  dist;
            for(auto &p:dp[i])
                pos.push_back(p.first), dist.push_back(p.second);

            int sz = pos.size();
            for(int j=1;j<sz;j++){
                if(dist[j-1]==inf) continue;
                dist[j] = min(dist[j],dist[j-1] + (pos[j]-pos[j-1])*loss[i]);
            } 
            for(int j=sz-2;j>=0;j--){
                if(dist[j+1]==inf) continue;
                dist[j] = min(dist[j],dist[j+1] + (pos[j+1]-pos[j])*loss[i]);
            }  

            int ptr = 0;
            for(auto &p:dp[i]){
                p.second = dist[ptr++];
            }

            for(auto &e:arr[i]){
                auto &valor = dp[e[1]][e[2]];
                if(dp[i][e[0]]!=inf)
                    valor = min(valor,dp[i][e[0]]-e[3]);
            }
        }

        ll answ = dp[n][m];
        if(answ==inf){
            cout << "NO ESCAPE\n";
        }
        else{
            cout << answ <<"\n";
        }
    }
    return 0;
}