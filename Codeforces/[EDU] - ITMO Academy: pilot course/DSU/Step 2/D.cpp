#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

struct DSU{
    vector<int> parent, dist, ht;

    DSU(int n){
        parent.assign(n+1,0);
        for(int i=1;i<=n;i++)
            parent[i] = i;
        ht.assign(n+1,0);
    }

    pair<int,int> find(int x){
        if(x==parent[x])
            return {x,0};
        auto p = find(parent[x]);
        parent[x] = p.first;
        ht[x]+=p.second;
        return {parent[x],ht[x]};
    }

    void _union(int x, int y){
        x = find(x).first, y = find(y).first;
        if(x!=y){
            parent[x] = y;
            ht[x]+=1;
        }
    }
};

int main(){
    int n, m;
    
    cin >> n >> m;
    DSU st(n+1);
    for(int i=0;i<m;i++){
        int op, a, b;
        cin >> op >> a;
        if(op==1){
            cin >> b;
            st._union(a,b);
        }
        else{
            st.find(a);
            cout << st.ht[a] <<"\n";
        }
    }


    return 0;
}