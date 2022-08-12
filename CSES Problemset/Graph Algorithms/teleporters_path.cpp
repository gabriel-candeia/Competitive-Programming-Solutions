#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

multiset<int> adj[maxn];
vector<int> answ;
int visited[maxn], indg[maxn];

int connected(int u){
    int qtd = 1;
    visited[u] = 1;
    for(auto v:adj[u]){
        if(!visited[v]){
            qtd+=connected(v);
        }
    }
    return qtd;
}

void solve(int u){
    while(adj[u].size()){
        int v = (*adj[u].begin());  
        adj[u].erase(adj[u].begin());
        solve(v);
    }
    answ.push_back(u);
}

int main(){
    int n, m, cnt=0;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        indg[b]++;
    }
    indg[1]++;
    adj[n].insert(1);

    int u = 1;
    for(int i=1;i<=n;i++){
        cnt += (indg[i]>=1 && adj[i].size()>=1);
    }
    int v = connected(u);

    bool ok = (v==cnt);
    for(int i=1;i<=n;i++){
        ok = (ok && ( adj[i].size()==0 || (indg[i]==adj[i].size())));
    }

    if(ok){
        int fst = 0;
        solve(u);
        reverse(answ.begin(),answ.end());
        answ.pop_back();
        for(int i=0;i<answ.size();i++){
            if(answ[i]==n && answ[i+1]==1){
                fst = i;
                break;
            }
        }
        //cout << fst <<" "<<answ.size()<< "\n";
        for(int i=(fst+1)%answ.size(), cnt = 0; cnt<answ.size(); i=(i+1)%answ.size(), cnt++){
            //cout << i << " ";
            cout << answ[i] << " ";
        }
        cout<<"\n";
    }
    else{
        cout <<"IMPOSSIBLE" <<"\n";
    }

    return 0;
}