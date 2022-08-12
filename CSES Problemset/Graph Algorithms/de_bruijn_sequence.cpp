#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

multiset<int> adj[maxn];
vector<int> answ;

void solve(int u){
    while(adj[u].size()){
        int v = (*adj[u].begin());
        adj[u].erase(adj[u].begin());
        solve(v);
    }
    answ.push_back(u);
}

int main(){
    int n;

    cin >> n;
    if(n==1){ cout << "01\n"; return 0;}
    for(int i=0;i<1<<(n-1);i++){
        int msk = (i&((1<<(n-2))-1))<<1;
        adj[i].insert(msk);
        adj[i].insert(msk|1);
    }

    solve(0);
    vector<int> resp;
    for(int i=1;i<answ.size();i++){
        resp.push_back(answ[i]&1);
    }
    for(int i=0;i<n-1;i++){
        resp.push_back(resp[i]);
    }
    for(auto x:resp)
        cout << x;
    cout<<"\n";

    return 0;
}