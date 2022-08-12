#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

vector<int> adj[maxn];

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, k;
        queue<int> q;
        vector<int> cor;
        cin >> n >> k;

        cor.assign(n+1,0);
        for(int i=0;i<k;i++){
            int x;
            cin >> x;
            cor[x] = 1;
            q.push(x);
        }

        for(int i=0;i<n-1;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        cor[1] = 2;
        q.push(1);
        int u;
        while(q.size()){
            u = q.front(), q.pop();
            for(auto v:adj[u]){
                if(cor[v]==0){
                    cor[v] = cor[u];
                    q.push(v);
                }
            }
        }

        bool poss = false;
        for(int i=2;i<=n;i++){
            if(cor[i]==2 && adj[i].size()==1){
                poss = true;
            }
        }

        cout << ((poss) ? "YES" : "NO") << "\n";

        for(int i=0;i<=n;i++) adj[i].clear();
    }

    return 0;
}