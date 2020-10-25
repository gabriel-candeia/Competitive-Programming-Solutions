#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e18;
int n, m;
vector<vector<pair<ll,ll>>> adj;
vector<int> pai;
ll dijkstra(ll s, ll target){
    vector<ll> d(n+1,inf), visited(n+1,false);
    priority_queue<tuple<ll,ll>> pq;
    d[s] = 0;
    pq.push({-d[s],s});
    ll u, dist;
    pai[s] = -1;
    while(pq.size()){
        tie(dist,u) = pq.top(); pq.pop();
        if(!visited[u]){
            visited[u];
            for(auto e:adj[u]){
                if(-dist+e.second < d[e.first]){
                    d[e.first] = -dist+e.second;
                    pai[e.first] = u;
                    pq.push({-d[e.first],e.first});
                }
            }
        }
    }

    return d[target];
}

int main(){
    while(cin >> n >> m){
        if(!n && !m)
            break;
        int x, y, z, d;
        adj.assign(n+1,vector<pair<ll,ll>>());
        pai.assign(n+1,-1);
        for(int i=0;i<m;i++){
            cin >> x >> y >> z;
            adj[x].push_back({y,z});
            adj[y].push_back({x,z});
        }
        cin >> d;

        ll answ = dijkstra(1,d);
        if(answ<=120)
            cout << "Will not be late. ";
        else
            cout << "It will be " << answ-120 << " minutes late. ";
        cout << "Travel time - " << answ << " - best way - ";
        while(d!=1){
            cout << d << " ";
            d = pai[d];
        }
        cout<<"1\n";
    }

    return 0;
}