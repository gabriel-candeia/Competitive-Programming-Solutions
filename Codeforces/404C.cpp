#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> d;
    vector<pair<int,int>> g;
    vector<vector<int>> p, adj;
    int n, k;
    bool poss = true;
    
    cin >> n >> k;
    d.assign(n+1,0);
    p.assign(n+1,vector<int>());
    adj.assign(n+1,vector<int>());
    for(int i=1;i<=n;i++){
        cin >> d[i];
        p[d[i]].push_back(i);
        g.push_back({d[i],i});
    }
    sort(g.begin(),g.end());

    poss*=(p[0].size()==1);
    for(auto par:g){
        int i  = par.second;
        if(d[i] && p[d[i]-1].size()){
            int par = p[d[i]-1].back();
            while(p[d[i]-1].size() && adj[par].size()==k){
                p[d[i]-1].pop_back();
                par = p[d[i]-1].back();
            }
            if(p[d[i]-1].size()){
                adj[par].push_back(i);
                adj[i].push_back(par);
            }
            else{
                poss = false;
                break;
            }
        }
        else if(d[i]!=0){
            poss = false;
            break;
        }
    }

    if(poss){
        cout << n-1 << '\n';
        for(int i=1;i<=n;i++){
            for(auto v:adj[i]){
                if(v>i){
                    cout << i << ' ' << v << '\n';
                }
            }
        }
    }
    else{
        cout << -1 << '\n';
    }

    return 0;
}