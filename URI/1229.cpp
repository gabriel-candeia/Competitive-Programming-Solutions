#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

int n, cnt = 0;
vector<vector<int>> adj1, adj2;
map<map<int,int>,int> mp;

vector<int> center(const vector<vector<int>>& adj){
    int sz = n;
    vector<int> dg(n+1,0), leafs;
    for(int i=1;i<=n;i++){
        dg[i] = adj[i].size();
        if(dg[i]==1){
            leafs.push_back(i);
            dg[i] = -1;
        }
    }

    while(sz>2){
        sz -= leafs.size();
        vector<int> nextLeafs;
        for(auto u:leafs){
            for(auto v:adj[u]){
                if(dg[v]==-1) continue;
                dg[v]--;
                if(dg[v]<=1){
                    nextLeafs.push_back(v);
                    dg[v] = -1;
                }
            }
        }

        swap(nextLeafs,leafs);

    }
    if(leafs.size()==1)
        leafs.push_back(leafs[0]);

    return leafs;
}

int f(int u, int p, const vector<vector<int>>& adj){
    map<int,int> aux;
    for(auto v:adj[u]){
        if(v!=p){
            aux[f(v,u,adj)]++;
        }
    }
    if(mp.find(aux)==mp.end())
        mp[aux] = ++cnt;
    return mp[aux];
}

bool treeIsomorphism(const vector<vector<int>>& adj1, const vector<vector<int>>& adj2){
    auto c1 = center(adj1);
    auto c2 = center(adj2);
    assert(c1.size()>=2);
    assert(c2.size()>=2);
    //cout << c1[0] << " " << c1[1] <<"\n";
    //cout << c2[0] << " " << c2[1] <<"\n";
    pair<int,int> p1 = {f(c1[0],-1,adj1),f(c1[1],-1,adj1)};
    if(p1.first>p1.second) swap(p1.first,p1.second);

    pair<int,int> p2 = {f(c2[0],-1,adj2),f(c2[1],-1,adj2)};
    if(p2.first>p2.second) swap(p2.first,p2.second);
    
    return p1==p2;
}

int main(){
    while(cin >> n){
        adj1.assign(n+1,vector<int>());
        adj2.assign(n+1,vector<int>());
        
        for(int i=0;i<n-1;i++){
            int a, b;
            cin >> a >> b;
            adj1[a].push_back(b);
            adj1[b].push_back(a);
        }

        for(int i=0;i<n-1;i++){
            int a, b;
            cin >> a >> b;
            adj2[a].push_back(b);
            adj2[b].push_back(a);
        }
        
        cout << ((treeIsomorphism(adj1, adj2)) ? "S" : "N") <<"\n";

    }

    return 0;
}