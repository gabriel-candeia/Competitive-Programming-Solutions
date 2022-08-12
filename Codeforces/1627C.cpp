#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

int answ[maxn];
vector<pair<int,int>> adj[maxn];

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back({b,i});
            adj[b].push_back({a,i});
        }

        int u = 0;
        bool poss = true;
        for(int i=1;i<=n;i++){
            if(adj[i].size()>=3){
                
                poss = false;
            }
            if(adj[i].size()==1){
                u = i;
            }
        }

        if(poss){
            int peso = 2, last = 0;
            for(int i=1;i<=n;i++){
                for(auto v:adj[u]){
                    if(v.first!=last){
                        answ[v.second] = peso;
                        peso = (peso==2) ? 5 : 2;
                        last = u;
                        u = v.first;
                        break;
                    }
                }
            }
            for(int i=1;i<n;i++){
                cout << answ[i] << " ";
            }cout<<"\n";
        }
        else{
            cout << -1 <<"\n";
        }

        for(int i=1;i<=n;i++)
            adj[i].clear();
        
    }

    return 0;
}