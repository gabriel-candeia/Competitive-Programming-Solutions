#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

struct DSU{
    vector<int> parent, rnk;

    DSU(int n){
        parent.assign(n+1,0);
        for(int i=1;i<=n;i++)
            parent[i] = i;
        rnk.assign(n,0);
    }

    int find(int x){
        return (x==parent[x]) ? x : parent[x] = find(parent[x]);
    }

    void _union(int x, int y){
        x = find(x), y = find(y);
        if(x!=y){
            parent[x] = y;
        }
    }
};

int n, q;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >>n >> q;
    DSU staux(n+1), st(n+1);

    for(int i=1;i<=q;i++){
        int op, a, b;
        cin >> op >> a >> b;
        if(op==1){
            st._union(a,b);
            if(b==a+1) staux._union(a,b);
        }
        else if(op==2){
            for(int j=a+1;j<=b;j=staux.find(j)){
                
                st._union(a,j);
                if(j==n) break;
                staux._union(j,j+1);
            }
            
        }
        else{
            cout << (st.find(a)==st.find(b) ? "YES" : "NO") <<'\n';
        }
    }

    return 0;   
}