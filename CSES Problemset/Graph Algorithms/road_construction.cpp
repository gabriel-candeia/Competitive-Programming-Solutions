#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct DSU{
    vector<int> parent, rnk, sz;

    DSU(int n){
        parent.assign(n+1,0);
        for(int i=1;i<=n;i++)
            parent[i] = i;
        rnk.assign(n+1,0);
        sz.assign(n+1,1);
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
            sz[x]+=sz[y];
            return true;
        }
        return false;
    }
};

int main(){
    int n, m;
    int answ = 1;

    cin >> n >> m;
    DSU st(n);
    int cc = n;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        cc -= st._union(a,b);
        answ = max(answ,st.sz[st.find(a)]);
        cout << cc << " " << answ <<"\n";
    }

    return 0;
}