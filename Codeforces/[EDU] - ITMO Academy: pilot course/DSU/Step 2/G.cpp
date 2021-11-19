#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

struct DSU{
    vector<int> parent, rnk;

    DSU(int n){
        parent.assign(n+1,0);
        for(int i=1;i<=n;i++)
            parent[i] = i;
        rnk.assign(n,0);
    }

    int find(int x){
        return (x==parent[x]) ? x : parent[x] = find(parent[x]);
    }

    bool _union(int x, int y){
        x = find(x), y = find(y);
        if(x!=y){
            if(rnk[x]<rnk[y]){
                parent[x] = y;
            }
            else{
                parent[y] = x;
                rnk[x] += (rnk[y]==rnk[x]);
            }
            return true;
        }
        return false;
    }
};

int n, m;
vector<array<ll,4>> edges;

ll solve(){
    ll answ = 0;

    DSU st(n+1);
    sort(edges.begin(),edges.end());

    for(int i=0;i<edges.size();i++){
        if(st._union(edges[i][1],edges[i][2])){
            answ = max(answ,edges[i][0]);
        }
    }

    return answ;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0;i<m;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c,a,b,i+1});
    }

    ll answ = solve();
    cout << answ <<"\n";

    return 0;
}
