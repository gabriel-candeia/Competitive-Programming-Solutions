#include<bits/stdc++.h>
#define maxn int(300)
using namespace std;

int n;
int visited[maxn];
vector<int> adj[maxn];

int marcaCiclo(int u, int p, int s, int cnt){
    if(visited[u])
        return u;
    visited[u] = 1;
    int ret = 0;
    for(auto v:adj[u]){
        if(v!=p){
            ret =  marcaCiclo(v,u,s,v==s);
            if(ret){
                visited[v] = 2;
                break;
            }
        }
    }
    return ret;
}

bool dfs(int u, int p){
    visited[u] = 2;
    for(auto v:adj[u]){
        if(visited[v]!=0){
            if(p==v) continue;
            else return false;
        }
        else{
            dfs(v,u);
        }
    }
    return true;
}

int main(){
    int m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int start = -1;
    for(int i=1;i<=n;i++){
        if(marcaCiclo(i,-1,i,0)){
            start = i;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(visited[i]==1)
            visited[i] = 0;
        else if(visited[i]==2)
            visited[i] = 1;
    }

    bool ok = (start!=-1);
    int cnt = 0;
    for(int i=1;i<=n;i++){
        //cout << visited[i] <<"\n";
        if(visited[i]==1){
            bool flag = false;
            for(auto v:adj[i]){
                if(visited[v]==0){
                    ok = ok && dfs(v,i);
                    cnt++;
                    flag = true;
                }
                if(ok==false)
                    break;
            }
            cnt += (1-flag);
            if(ok==false)
                break;
        }
    }

    int acm = 0;
    for(int i=1;i<=n;i++){
        acm += (visited[i]!=0);
    }

    //cout << ok << " " << cnt << " " << acm <<"\n";
 
    cout << ((ok && cnt>=3 && acm==n) ? "FHTAGN!" : "NO") <<"\n";

    return 0;
}