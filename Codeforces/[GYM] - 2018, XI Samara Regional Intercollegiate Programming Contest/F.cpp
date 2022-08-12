#include<bits/stdc++.h>
#define maxn int(1e3+3)
using namespace std;

bool ciclo = false;
vector<int> adj[maxn], visited;
int sub[maxn][maxn];
vector<pair<int,int>> best;
int broot=0, root=1;
int n;
bool ok = true;

void dfs(int u, int p){
    visited[u] = 1;

    int cnt1 = 0, cnt2 = 0;
    for(auto v:adj[u])
        cnt1 += (v==p), cnt2 += (u==v);

    if(cnt1>1 || cnt2) ciclo = true;

    for(auto v:adj[u]){
        if(visited[v]==1 && v!=p){
            ciclo = true;
        }
        if(!visited[v]){
            dfs(v,u);
        }
    }

    visited[u] = 2;
}

void teste(int u, int p){
    visited[u] = 1;
    for(auto v:adj[u]){
        if(v!=p){
            teste(v,u);
        }
    }

    for(int i=1;i<=n;i++){
        if(i!=u){
            ok = (ok && (sub[u][i]==0));
        }
    }

    for(int i=1;i<=n;i++){
        if(visited[i]==1){
            sub[i][u]--;
        }
    }
    visited[u]==2;
}

int main(){


    cin >> n;
    best.assign(n+1,{n+1,-1});
    for(int i=1;i<=n;i++){
        int c;
        cin >> c;
        if(c>=broot){
            root = i;
            broot = c;
        }
        for(int j=0;j<c;j++){
            int x;
            cin >> x;
            if(x==i)
                ciclo = true;
            sub[i][x]++;
            if(best[x].first>c){
                best[x] = {c,i};
            }
        }
    }


    for(int i=1;i<=n;i++){
        if(best[i].second!=-1){
            adj[i].push_back(best[i].second);
            adj[best[i].second].push_back(i);
        }
    }

    visited.assign(n+1,0);
    dfs(root,-1);
    int cnt = 0;
    for(int i=1;i<=n;i++){
        cnt += (visited[i]!=0);

    }

    if(!ciclo && cnt==n){
        visited.assign(n+1,0);
        teste(root,-1);

        if(ok){
            cout << "YES\n";
            for(int i=1;i<=n;i++){
                if(best[i].second!=-1){
                    cout <<  best[i].second << " " << i <<"\n";
                }
            }      
        }    
        else{
            cout << "NO\n";
        }
    }
    else{
        cout << "NO\n";
    }

    return 0;
}