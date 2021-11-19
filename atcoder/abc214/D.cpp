#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
using namespace std;

int n;
vector<tuple<ll,int,int>> edges;

struct dsu{
    vector<int> rnk, parent, wt;

    dsu(int n){
        rnk.assign(n+1,0);
        parent.assign(n+1,0);
        wt.assign(n+1,0);

        for(int i=0;i<n;i++){
            wt[i] = 1;
            parent[i] = i;
        }
    }

    int find(int x){
        return ((x==parent[x]) ? x : parent[x] = find(parent[x]));
    }

    void _union(int x, int y){
        x = find(x), y = find(y);
        if(x!=y){
            if(rnk[x]<rnk[y]){
                parent[x] = y;
                wt[y]+=wt[x];
            }
            else{
                parent[y] = x;
                wt[x]+=wt[y];
                rnk[x]+=(rnk[x]==rnk[y]);
            }
        }
    }

    int get(int u){
        return wt[find(u)];
    }
};

int main(){
    cin >> n;

    for(int i=0;i<n-1;i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges.push_back(tuple<int,int,int>{c,a,b});
    }

    sort(edges.begin(),edges.end());
    ll c, a, b, answ = 0;
    dsu alg(n+1);
    for(auto e:edges){
        tie(c,a,b) = e;

        answ += c*alg.get(a)*alg.get(b);
        alg._union(a,b);
    }

    cout << answ <<"\n";

    return 0;
}