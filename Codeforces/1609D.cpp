#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

struct DSU{
    vector<int> parent, rnk, sz;

    DSU(int n) : parent(n+1,0), rnk(n+1,0), sz(n+1,1){
        for(int i=0;i<=n;i++) parent[i] = i;
    }

    int find(int x){
        return (x==parent[x]) ? x : parent[x] = find(parent[x]);
    }

    int _union(int x, int y){
        x = find(x), y = find(y);
        if(x!=y){
            if(rnk[x]<rnk[y]) swap(x,y);
            parent[x] = y;
            rnk[y]+=(rnk[x]==rnk[y]);
            sz[y]+=sz[x];
            return 0;
        }
        return 1;
    }

    int get_maiores(int k){
        vector<int> temp;
        for(int i=1;i<=parent.size();i++){
            if(i==parent[i]){
                temp.push_back(sz[i]);
            }
        }
        sort(temp.rbegin(),temp.rend());
        int answ = 0;
        for(int i=0;i<min(k,(int)temp.size());i++){
            answ += temp[i];
        }
        return answ;
    }
};

int main(){
    int pegar = 1, n, d;

    cin >> n >> d;
    DSU st(n);

    for(int i=0;i<d;i++){
        int a, b;
        cin >> a >> b;
        pegar += st._union(a,b);
        cout << st.get_maiores(pegar)-1 <<"\n";
    }

    return 0;
}