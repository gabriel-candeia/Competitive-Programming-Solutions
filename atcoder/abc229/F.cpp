#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct DSU{
    vector<int> parent, rnk, color;

    DSU(int n){
        parent.assign(n+1,0), rnk.assign(n+1,0), color.assign(n+1,0);
        iota(parent.begin(),parent.end(),0);
    }

    int find(int x){
        if(parent[x]==x)
            return x;
        int p = find(parent[x]);
        color[x] = color[x]^color[parent[x]];
        return parent[x] = p;
    }

    bool isOk(int x, int y){
        return (find(x)!=find(y) || color[x]!=color[y]);
    }

    void _union(int x, int y){
        int xp = find(x), yp = find(y);
        if(xp!=yp){
            if(rnk[xp]>rnk[yp]) swap(xp,yp), swap(x,y);
            parent[xp] = yp;
            rnk[yp] += (rnk[yp]==rnk[xp]);
            if(color[x]==color[y]) color[xp] = 1;
        }
    }
};

int main(){
    int n;
    vector<array<int,3>> edges;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        edges.push_back({x,0,i});
    }

    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        edges.push_back({x,i,((i==n) ? 1 : i+1)});
    }

    sort(edges.rbegin(),edges.rend());
    DSU st(n);
    ll answ = 0;
    for(auto e:edges){
        if(!st.isOk(e[1],e[2])) 
            answ+=e[0];
        else
            st._union(e[1],e[2]);
    }

    cout << answ <<"\n";

    return 0;
}