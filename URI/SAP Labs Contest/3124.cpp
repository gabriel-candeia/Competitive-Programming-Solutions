#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct dsu{
    vector<ll> parent, rnk;

    dsu(int n){
        parent.assign(n+1,0);
        rnk.assign(n+1,0);
        for(int i =0;i<=n;i++)
            parent[i] = i;
    }

    ll find(ll x){
        return (x==parent[x]) ? x : parent[x] = find(parent[x]);
    }

    bool _union(ll x, ll y){
        x = find(x);
        y = find(y);
        if(x!=y){
            if(rnk[x]<rnk[y]){
                parent[y] = x;
            }
            else{
                parent[x] = y;
                rnk[y] += (rnk[x]==rnk[y]);
            }
            return true;
        }
        return false;
    }
};

int n;
vector<tuple<double,ll,ll>> edges;
vector<pair<ll,ll>> points;


double dist(pair<ll,ll> a, pair<ll,ll> b){
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

double kruskal(){
    dsu aux = dsu(n);
    double cost = 0, w;
    int x, y;

    for(auto e : edges){
        tie(w,x,y) = e;
        if(aux._union(x,y))
            cost += w;
    }
    
    return cost;
}


int main(){
    int x, y;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        points.push_back({x,y});
    }

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            edges.push_back({dist(points[i],points[j]),i+1,j+1});
    sort(edges.begin(),edges.end());

    cout << fixed << setprecision(10) << kruskal() << '\n';

    return 0;
}