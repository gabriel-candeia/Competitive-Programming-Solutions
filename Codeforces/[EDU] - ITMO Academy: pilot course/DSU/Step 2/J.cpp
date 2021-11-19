#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
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
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m;
    int shift = 0;
    cin >> n >> m;
    int answ = -1;

    DSU st(n+1);
    for(int i=0;i<m;i++){
        ll a, b;
        cin >> a >> b;
        if(answ==-1 && !st.isOk(a,b)){
            answ = i+1;
        }
        st._union(a,b);
    }

    cout << answ <<"\n";

    return 0;
}
