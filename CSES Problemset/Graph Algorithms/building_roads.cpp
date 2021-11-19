#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

struct dsu{
    vector<int> parent, rnk;

    dsu(int n){
        parent.assign(n+1,0), rnk.assign(n+1,0);
        for(int i=0;i<=n;i++) parent[i] = i;
    }

    int find(int x){
        return ((parent[x]==x) ? x : parent[x] = find(parent[x]));
    }

    void _union(int x, int y){
        x = find(x), y = find(y);
        if(x!=y){
            if(rnk[x]>rnk[y])
                parent[y] = x;
            else{
                parent[x] = y;
                rnk[y] += (rnk[x]==rnk[y]);
            }
        }
    }
};


int main(){
    int n, m;
    cin >> n >> m;

    dsu alg(n);
    for(int i=0, x, y;i<m;i++){
        cin >> x >> y;
        alg._union(x,y);
    }

    vector<int> answ;
    for(int i=1;i<=n;i++)
        if(alg.parent[i]==i)
            answ.push_back(i);
    
    cout << answ.size()-1 << "\n";
    for(int i=1;i<answ.size();i++){
        cout << answ[0] << " " << answ[i] << "\n";
    }

    return 0;
}