#include<bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> parent, rnk, size;
    int cc = 0;

    DSU(int n){
        parent.assign(n,0);
        for(int i=1;i<n;i++)
            parent[i] = i;
        rnk.assign(n,0);
        size.assign(n,1);
        cc = n;
    }

    int find(int x){
        return (x==parent[x]) ? x : parent[x] = find(parent[x]);
    }

    void _union(int x, int y){
        x = find(x), y = find(y);
        if(x!=y){
            if(rnk[x]<rnk[y]){
                parent[x] = y;
                size[y]+=size[x];
            }
            else{
                parent[y] = x;
                rnk[x] += (rnk[y]==rnk[x]);
                size[x]+=size[y];
            }
            cc--;
        }
    }
};

int main(){
    int n, m, q;
    vector<pair<int,int>> edges;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        edges.push_back({a,b});
    }

    cin >> q;
    vector<pair<int,int>> queries(q,{0,0});
    vector<int> used(m,0);
    for(int i=0;i<q;i++){
        cin >> queries[i].first;
        if(queries[i].first==1){
            cin >> queries[i].second;
            queries[i].second--;
            used[queries[i].second] = 1;
        }
    }
    DSU st(n+1);
    for(int i=0;i<m;i++){
        if(used[i]==0){
            st._union(edges[i].first,edges[i].second);
        }
    }
    vector<int> answ;
    for(int i=queries.size()-1;i>=0;i--){
        if(queries[i].first==1){
            int j = queries[i].second;
            st._union(edges[j].first,edges[j].second);
        }
        else{
            answ.push_back(st.size[st.find(0)]-1);
        }
    }

    reverse(answ.begin(),answ.end());
    for(auto &x:answ)
        cout << x <<"\n";

    return 0;
}