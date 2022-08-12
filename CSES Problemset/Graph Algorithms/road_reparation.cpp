#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct DSU{
    vector<int> parent, rnk;

    DSU(int n){
        parent.assign(n+1,0);
        for(int i=1;i<=n;i++)
            parent[i] = i;
        rnk.assign(n+1,0);
    }

    int find(int x){
        return (x==parent[x]) ? x : parent[x] = find(parent[x]);
    }

    bool _union(int x, int y){
        x = find(x), y = find(y);
        if(x!=y){
            if(rnk[x]<rnk[y]) swap(x,y);
            parent[y] = x;
            rnk[x] += (rnk[y]==rnk[x]);
            return true;
        }
        return false;
    }
};

int main(){
    int n, m;
    vector<array<int,3>> edges;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c,a,b});
    }

    ll answ = 0;
    int cc = n;
    sort(edges.begin(),edges.end());
    DSU st(n);
    for(auto e:edges){
        if(st._union(e[1],e[2])){
            answ += e[0];
            cc--;
        }
    }

    if(cc==1){
        cout << answ <<"\n";
    }
    else{
        cout << "IMPOSSIBLE\n";
    }   

    return 0;
}