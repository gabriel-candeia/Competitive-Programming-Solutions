#include<bits/stdc++.h>
using namespace std;
vector<int> parent, visited;
vector<vector<int>> adj;
bool cycle=false;
int start, last;


void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    parent[u] = -1;
    while(q.size()){
        u = q.front(); q.pop();
        for(auto v:adj[u]){
            if(!visited[v]){
                visited[v] = visited[u]+1;
                parent[v] = u;
                q.push(v);
            }
            else if(v!=parent[u]){
                start = u;
                last = v;
                cycle = true;
            }
        }
    }
}

void findCycle(int start, int end){
    queue<int> q;
    int u;
    q.push(start);
    visited[start] = 1;
    parent[start] = -1;
    while(q.size()){
        u = q.front(); q.pop();
        for(auto v:adj[u]){
            if(!visited[v] && (u!=start || v!=end)){
                visited[v] = visited[u]+1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int main(){
    int n, k, m, x, y;
    
    cin >> n >> m >> k;
    adj.assign(n+1,vector<int>());
    visited.assign(n+1,0);
    parent.assign(n+1,0);

    for(int i=0;i<m;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bfs(i);
        }
    }
    if(!cycle){
        cout << 1 << '\n';
        int cnt=0;
        for(int i=1;i<=n;i++){
            cnt+=visited[i]%2;
        }
        int rem = k/2 + (k%2!=0);
        int sel = 1;
        if(cnt<rem){
            sel = 0;
        }
        for(int i=1;i<=n && rem;i++){
            if(visited[i]%2==sel){
                rem--;
                cout << i <<' ';
            }
        }
        cout << '\n';
    }
    else{
        visited.assign(n+1,0);
        findCycle(start,last);
        vector<int> answ;
        while(last!=-1){
            answ.push_back(last);
            last = parent[last];
        }
        if(answ.size()<=k){
            cout << 2 << '\n';
            cout << answ.size() << '\n';
            for(auto x:answ){
                cout << x << ' ';
            }
            cout << '\n';
        }
        else{
            cout << 1 << '\n';
            for(int i=0;i<k;i+=2){
                cout << answ[i] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}