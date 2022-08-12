#include<bits/stdc++.h>
#define maxm int(256)
#define maxn int(1e4+5)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

const int inf = 1e9;
int dist[2][maxn][maxm], answ[2][maxm];
vector<array<int,2>> adj[maxn];
vector<array<int,2>> events[maxn];

int main(){
    int t;
    fastio();

    cin >> t;
    while(t--){
        int n, m, k, e, lim;
        cin >> n >> m >> k;

        for(int i=0;i<=n;i++)
            adj[i].clear(), events[i].clear();
        for(int i=0;i<(1<<k);i++)
            answ[0][i] = answ[1][i] = inf;
        for(int i=0;i<=n;i++)
            for(int j=0;j<(1<<k);j++)
                dist[0][i][j] = dist[1][i][j] = inf;

        for(int i=0;i<m;i++){
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }

        cin >> e >> lim;
        for(int i=0;i<e;i++){
            int p, x, t;
            cin >> p >> x >> t;
            events[x].push_back({p-1,t});
        }

        int s1, s2;
        cin >> s1 >> s2;
        priority_queue<tuple<int,int,int,int>> pq;
        dist[0][s1][0] = 0, pq.push({-dist[0][s1][0],0,s1,0});
        dist[1][s2][0] = 0, pq.push({-dist[1][s2][0],1,s2,0});

        int d, flag, u, msk;
        while(pq.size()){
            tie(d,flag,u,msk) = pq.top(), pq.pop(), d = -d;
            //cout << flag <<" " << u << " " << msk <<"\n";

            if(d > dist[flag][u][msk]) continue;

            for(auto e:adj[u]){
                if(d+e[1] < dist[flag][e[0]][msk]){
                    dist[flag][e[0]][msk] = d+e[1];
                    pq.push({-dist[flag][e[0]][msk],flag,e[0],msk});
                }
            }

            for(auto e:events[u]){
                if(!(msk&(1<<e[0])) && e[1]<=dist[flag][u][msk|(1<<e[0])] && e[1]>=d){
                    dist[flag][u][msk|(1<<e[0])] = e[1];
                    pq.push({-dist[flag][u][msk|(1<<e[0])],flag,u,msk|(1<<e[0])});
                }
            }
        }

        for(int ks=0;ks<2;ks++){
            for(int i=1;i<=n;i++){
                for(int j=0;j<(1<<k);j++){
                    answ[ks][j] = min(answ[ks][j],dist[ks][i][j]);
                }
            }
        }
        //cout << dist[1][3][5] <<"\n";

        int resp = inf, aux = ((1<<k)-1);
        for(int j=0;j<(1<<k);j++){

            resp = min(resp,max(answ[0][j],answ[1][(j^aux)]));
        }
        if(resp>lim)
            resp = -1;

        cout << resp <<"\n";
    }

    return 0;
}