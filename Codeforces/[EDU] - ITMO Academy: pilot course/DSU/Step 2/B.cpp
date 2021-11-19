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

int n;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >>n;
    DSU st(n+1);

    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a;
        b = st.find(a);
        cout << b <<" ";
        st._union(b,((b==n) ? 1 : b+1));
    }cout<<"\n";

    return 0;   
}