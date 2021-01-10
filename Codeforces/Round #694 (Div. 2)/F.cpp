#include<bits/stdc++.h>
#define maxn int(3e5+5)
using namespace std;

int n, m, color[maxn];
vector<int> adj[maxn];
bool solve(int u){
    int it=0;
    queue<int> q;
    q.push(u); color[u] = 1;

    while(q.size()){
        u = q.front(); q.pop();
        it++;

        bool flag=false;
        for(auto v:adj[u])
            if(color[v]==1)
                flag = true;

        if(!flag) color[u] = 1;
        
        for(auto v:adj[u]){
            if(color[v]==0){
                color[v] = 2;
                q.push(v);
            }
        }
    }

    return (it==n);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<=n;i++){
            adj[i].clear();
            color[i] = 0;
        }

        int x, y;
        for(int i=0;i<m;i++){
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        if(solve(1)){
            cout << "YES\n";
            int acm =0;
            for(int i=1;i<=n;i++)
                acm+=(color[i]==1);

            cout << acm << "\n";
            for(int i=1;i<=n;i++)
                if(color[i]==1)
                    cout << i << " ";
            cout<<'\n';
        }
        else{
            cout << "NO\n";
        }

    }

    return 0;
}