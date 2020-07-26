#include<bits/stdc++.h>
#define N 1005
using namespace std;

vector<int> answ;
bool poss = true;
int cnt=1;
stack<int> st;

vector<bool> inPath;
void is_dag(vector<vector<int>>& adj, int u,vector<bool>& visited){
    visited[u] = true;
    inPath[u] = true;
    for(auto v:adj[u]){
        if(inPath[v]){
            poss = false;
        }
        else if(!visited[v]){
            is_dag(adj,v,visited);
        }
    }
    inPath[u] = false;

    st.push(u);
}

void solve(vector<vector<int>>& adj, int u, vector<bool>& visited){
    visited[u] = true;
    
    for(auto v:adj[u]){
        if(!visited[v]){
            solve(adj,v,visited);
        }
        answ[u] = max(answ[u],answ[v]+1);
    }
}

vector<int> mp, rnk;

int find(int j){
    return ((mp[j]==j) ? j : mp[j] = find(mp[j]));
}

void uniao(int i, int j){
    i = find(i);
    j = find(j);
    if(i!=j){
        if(rnk[i]>rnk[j]){
            mp[j] = i;
        }
        else{
            mp[i] = j;
            rnk[j] += (rnk[i]==rnk[j]);
        }
    }
}

int main(){
    int n, m;
    char grid[N][N];
    
    cin >> n >> m;
    answ.assign(n+m,0);
    mp.assign(n+m,0);
    rnk.assign(n+m,0);
    for(int i=0;i<n+m;i++){
        mp[i] = i;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> adj(n+m,vector<int>());
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='='){
                uniao(i,n+j);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='>'){
                adj[find(i)].push_back(find(n+j));
            }
            else if(grid[i][j]=='<'){
                adj[find(n+j)].push_back(find(i));
            }
        }
    }

    vector<bool> visited(n+m,false);
    inPath.assign(n+m,0);
    answ.assign(n+m,1);
    for(int i=0;i<n+m;i++){
        if(!visited[i]){
            is_dag(adj,i,visited);
        }
    }
    if(poss){
        visited.assign(n+m,false);
        while(st.size()){
            int u = st.top(); st.pop();
            if(!visited[u]){
                solve(adj,u,visited);
            }
        }
        cout << "YES\n";
        for(int i=0;i<n;i++){
            cout << answ[find(i)] << ' ';
        }cout << "\n";
        for(int i=n;i<n+m;i++){
            cout << answ[find(i)] << ' ';
        }cout << "\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}