#include<bits/stdc++.h>
#define maxn int(25e4+5)
#define maxm 11
#define ll int
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

const ll inf = 1e8;
vector<pair<ll,ll>> adj[maxn];

ll dist[maxn][maxm];
ll visited[maxn][maxm];

int main(){
    fastio();
    int n, m, k;

    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            ll a;
            cin >> a;
            int u = i*m+j, v =  i*m+j+1;
            //cout << u << " " << v <<"\n";
            adj[u].push_back({v,a});
            adj[v].push_back({u,a});
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            ll a;
            cin >> a;
            int u = i*m+j, v =  (i+1)*m+j;
            adj[u].push_back({v,a});
            adj[v].push_back({u,a});
        }
    }

    //(i, j) dist[i*n+j+1][k+1]

    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxm;j++)
            dist[i][j] = inf;
    }

    bool impar = k%2;
    k = k/2;

    priority_queue<array<ll,3>> pq;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i*m+j][0] = 0;
            pq.push({-dist[i*m+j][0],i*m+j,0});
        }
    }
    
    ll d, u, iter;
    while(pq.size()){
        d = pq.top()[0], d = -d;
        u = pq.top()[1], iter = pq.top()[2];
        pq.pop();
        //tie(d,u,iter) = pq.top(), pq.pop(), d = -d;
        if(iter==k){ continue;}
        if(visited[u][iter]) continue;
        visited[u][iter] = 1;
        for(auto e:adj[u]){
            if(d+e.second<dist[e.first][iter+1]){
                dist[e.first][iter+1] = d+e.second;
                pq.push({-dist[e.first][iter+1],e.first,iter+1});
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(impar){
                cout << -1 << " ";
            }
            else{
                if(dist[i*m+j][k]==inf){
                    cout << -1 << " ";
                }
                else{
                    cout << 2*dist[i*m+j][k] <<" ";
                }
            }
        }
        cout <<"\n";
    }

    return 0;
}