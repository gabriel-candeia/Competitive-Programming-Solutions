#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

struct DSU{
    vector<int> parent, rnk;
    int cc;

    DSU(int n){
        parent.assign(n+1,0);
        rnk.assign(n+1,0);
        for(int i=1;i<=n;i++)
            parent[i] = i;
        cc = n;
    }

    int find(int x){
        return (x==parent[x]) ? x : parent[x] = find(parent[x]);
    }

    void _union(int x, int y){
        x = find(x), y = find(y);
        if(x!=y){
            if(rnk[y]<rnk[x]) swap(x,y);
            parent[x] = y;
            rnk[y] += (rnk[x]==rnk[y]);
            cc--;
        }
    }
};

vector<int> adj[maxn];

int main(){
    int n, m;

    cin >> n >> m;   
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        if(a>b)
            swap(a,b);
        adj[a].push_back(b);
    }

    vector<int> answ(n+1,0);
    DSU st(n);
    for(int i=n;i>=0;i--){
        answ[i] = st.cc-i;
        for(auto v:adj[i]){
            st._union(i,v);
        }
    }

    for(int i=1;i<=n;i++){
        cout << answ[i] << "\n";
    }


    return 0;
}