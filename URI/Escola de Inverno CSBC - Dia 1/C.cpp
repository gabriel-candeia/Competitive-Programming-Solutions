#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct dsu{
    vector<int> parent, rnk;

    dsu(int n){
        parent.assign(n+1,0), rnk.assign(n+1,1);
        for(int i=0;i<=n;i++)
            parent[i] = i;
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

ll solve(vector<array<ll,3>> edges, int n){
    ll answ = 0;
    dsu alg(n+1);
    sort(edges.rbegin(),edges.rend());

    for(auto e:edges)
        if(alg._union(e[1],e[2]))
            answ += e[0];

    return answ;
}


int main(){
    int t;

    cin >> t;
    while(t--){
        int k, x;
        cin >> k >> x;
        vector<ll> lotes;
        for(int i=0;i<k;i++){
            vector<array<ll,3>> edges;
            int n, m;
            cin >> n >> m;
            for(int i=0;i<m;i++){
                int a, b, c;
                cin >> a >> b >> c;
                edges.push_back(array<ll,3>{c,a,b});
            }
            lotes.push_back(solve(edges,n));
        }
        sort(lotes.rbegin(),lotes.rend());
        ll answ = 0;
        for(int i=0;i<k;i+=x)
            answ += lotes[i];
        cout << 2*answ <<'\n';
    }

    return 0;
}