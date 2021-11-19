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

    bool isSame(int x, int y){
        find(x), find(y);
        return color[x]==color[y];
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

    DSU st(n+1);
    for(int i=0;i<m;i++){
        ll op, a, b;
        cin >> op >> a >> b;
        int x, y;
        x = (a+shift>n) ? a+shift-n : a+shift;
        y = (b+shift>n) ? b+shift-n : b+shift;
        if(op==0){
            st._union(x,y);
        }
        else{
            bool answ = st.isSame(x, y);
            cout << (answ ? "YES" : "NO") <<"\n";
            if(answ) shift = (shift+1)%n;   
        }
    }

    return 0;
}
