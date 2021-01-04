#include<bits/stdc++.h>
#define maxn 30
using namespace std;

bool poss = true, presente[maxn];
int visited[maxn];
vector<int> answ;
vector<int> adj[maxn];
char grid[maxn][maxn];

void dfs(int u){
    
    visited[u] = 1;

    for(auto v:adj[u]){
        if(visited[v]==1)
            poss = false;
        else if(!visited[v])
            dfs(v);
    }

    visited[u] = 2;
    
    answ.push_back(u);
}


int main(){
    int cnt = 0, t;

    cin >> t;
    while(t--){
        for(int i=0;i<maxn;i++)
            adj[i].clear();
        answ.clear();
        memset(visited,0,sizeof(visited));
        memset(presente,0,sizeof(presente));
        poss = true;

        int h, w;
        cin >> h >> w;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> grid[i][j];
                presente[grid[i][j]-'A'] = true;
            }
        }
        
        for(int i=0;i<h-1;i++)
            for(int j=0;j<w;j++)
                if(grid[i][j]!=grid[i+1][j])
                    adj[grid[i+1][j]-'A'].push_back(grid[i][j]-'A');

        for(int i=0;i<maxn;i++)
            if(presente[i] && !visited[i])
                dfs(i);

        cout << "Case #" << ++cnt << ": ";
        if(!poss)
            cout << -1 << "\n";
        else{
            for(int i=answ.size()-1;i>=0;i--)
                cout << char(answ[i]+'A');
            cout<<'\n';
        }
    }

    return 0;
}