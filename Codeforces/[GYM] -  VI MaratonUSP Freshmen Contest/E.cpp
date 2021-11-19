#include<bits/stdc++.h>
#define maxn int(1e6+5)
using namespace std;

vector<int> adj[maxn], adjR[maxn];
vector<int> ord, visited;
void dfs(int u){
    visited[u] = 1;
    for(auto v:adj[u])
        if(!visited[v])
            dfs(v);
    ord.push_back(u);
}


int main(){ 
    map<string,int> mp;
    int cnt = 0;

    int n, m, start=0;
    cin >> n;
    string s, t;
    for(int i=0;i<n;i++){
        cin >> s;
        if(mp.find(s)==mp.end()){
            mp[s] = ++cnt;
        }
    }
    start = mp.size();

    cin >> m;
    for(int i=0;i<m;i++){
        int qtd;
        cin >> s >> qtd;
        if(mp.find(s)==mp.end()) mp[s] = ++cnt;
        set<string> temp;
        for(int j=0;j<qtd;j++){
            cin >> t;
            if(temp.find(t)!=temp.end()) continue;
            temp.insert(t);
            if(mp.find(t)==mp.end()) mp[t] = ++cnt;
            adj[mp[t]].push_back(mp[s]);
            adjR[mp[s]].push_back(mp[t]);
        }
    }

    visited.assign(cnt+1,0);
    for(int i=1;i<=cnt;i++)
        if(!visited[i])
            dfs(i);
    
    reverse(ord.begin(),ord.end());
    visited.assign(cnt+1,0);
    vector<int> ok(cnt+1,0);
    for(int i=1;i<=start;i++) visited[i] = true;
    
    for(auto u:ord){
        if(visited[u]){
            for(auto v:adj[u]){
                ok[v] += 1;
                if(ok[v]==adjR[v].size())
                    visited[v] = 1;
            }
        }
    }
    
    int answ = 0;
    
    for(int i=1;i<=cnt;i++){
        answ += (visited[i]);
        
    }

    cout << answ <<"\n";

    return 0;
}