#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, a, b;
    vector<vector<int>> adj;

    cin >> n >> m;
    adj.assign(n+1,vector<int>());
    for(int i=0;i<m;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> visited(n+1,0);
    vector<int> last(n+1,0);
    queue<int> q; 
    int u, cnt=n;

    q.push(1), visited[1] = true;
    
    while(q.size()){
        u = q.front(); q.pop();
        cnt--;
        for(auto v: adj[u]){
            if(!visited[v]){
                visited[v] = visited[u]+1;
                last[v] = u;
                q.push(v);
            }
        }
    }

    if(cnt==0){
        cout << "Yes\n";
        for(int i=2;i<=n;i++){
            cout << last[i] << '\n';
        }
    }
    else{
        cout << "No\n";
    }

    return 0;
}