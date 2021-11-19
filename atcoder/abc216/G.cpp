#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

//See CLRS 3rd edition 24.4 for more details

int n, m;
const int inf = 1e9;
vector<pair<int,int>> adj[maxn];

vector<int> solve(int s){
    vector<int> dist(maxn,inf);
    priority_queue<tuple<int,int>> pq;
    int d, u;

    dist[s] = 0;
    pq.push({-dist[s],s});

    while(pq.size()){
        tie(d, u) = pq.top(), pq.pop(), d = -d;
        

        if(d>dist[u]) continue;
        for(auto e:adj[u]){
            if(d+e.second<dist[e.first]){
                dist[e.first] = d+e.second;
                pq.push({-dist[e.first],e.first});
            }
        }

    }

    return dist;
}

int main(){
    cin >> n >> m;
    set<int> adj0;
    for(int i=0;i<m;i++){
        int l, r, x;
        cin >> l >> r >> x;
        if(l==1) adj0.insert(r);
        adj[l-1].push_back({r,r-l+1-x});
    }

    for(int i=0;i<n;i++){
        //number of zeros increases at most in 1 b_{i+1}-b_{i} <= 1
        adj[i].push_back({i+1,1});
    }

    for(int i=0;i<n;i++){
        //b_{i+1} is not less than b_{i}, b_{i}-b_{i+1} <= 0
        adj[i+1].push_back({i,0});
    }

    auto b = solve(0);
    for(int i=n+1;i;i--)
        b[i]-=b[i-1];

    for(int i=1;i<=n;i++){
        cout << !b[i] << " ";
    }cout<<"\n";

    return 0;
}