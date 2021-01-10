#include<bits/stdc++.h>
#define maxn int(4e5+5)
using namespace std;

int visited[maxn];
vector<int> adj[maxn];

int bfs(int u){
    queue<int> q;
    int cnt = 0, m=0;

    q.push(u); visited[u] = 1;
    while(q.size()){
        cnt++;
        u = q.front(); q.pop();

        for(auto v:adj[u]){
            if(!visited[v]){
                visited[v] = 1;
                q.push(v);
            }
            m++;
        }
    }
    m/=2;
    return ((m==cnt-1) ? cnt-1 : cnt); 
}

int main(){ 
    int n;
    vector<int> a, b;

    cin >> n; a.assign(n,0); b.assign(n,0);

    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }

    int answ = 0;
    for(int i=0;i<maxn;i++){
        if(!visited[i]){
            answ += bfs(i);
        }
    }

    cout<< answ <<'\n';
    return 0;
}