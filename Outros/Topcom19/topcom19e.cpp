#include<bits/stdc++.h>
#define maxn int(25)
using namespace std;

int n, m;
vector<int> dg;
vector<int> adj[maxn];
vector<vector<int>> answ;

void solve(int u, vector<int> &acm){
    if(acm.size()==n-1){
        acm.push_back(u);
        answ.push_back(acm);
        acm.pop_back();
    }
    else{
        dg[u] = -1;
        acm.push_back(u);
        for(auto v:adj[u]){
            dg[v]--;
        }
        for(int i=1;i<=n;i++){
            if(dg[i]==0){
                solve(i,acm);
            }
        }
        for(auto v:adj[u]){
            dg[v]++;
        }
        acm.pop_back();
        dg[u] = 0;
    }
}


int main(){
    int t, qtd=1;

    cin >> t;
    while(t--){
        answ.clear();
        cin >> n >> m;

        for(int i=1;i<=n;i++)
            adj[i].clear();

        dg.assign(n+1,0);
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b); dg[b]++;
        }

        vector<int> acm;
        for(int i=1;i<=n;i++){
            if(dg[i]==0)
                solve(i,acm);
        }
        cout << "Projeto " << qtd++ <<"\n";
        for(auto arr:answ){
            for(int i=0;i<n-1;i++){
                cout << arr[i] << " ";
            }
            cout << arr[n-1] <<"\n";
        }

    }

    return 0;
}
