#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<string> answ;
vector<int> visited, ord;
vector<bool> poss;

void dfs(int u){
    visited[u] = 1;
    for(auto v:adj[u]){
        if(visited[v]==1)
            poss[u] = false;
        else if(!visited[v])
            dfs(v);
        poss[u] = poss[u]&&poss[v];
    }
    visited[u] = 2;
    ord.push_back(u);
}

int main(){
    fastio();
    int n, t;
    char c;
    string s;
    adj.assign(26,vector<int>());
    answ.assign(26,"");

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> c >> s;
        if(s.size()==1 && s[0]==c)
            continue;
        for(auto x:s)
            adj[c-'a'].push_back(x-'a');
    }

    visited.assign(26,false);
    poss.assign(26,true);
    for(int i=0;i<26;i++)
        if(!visited[i])
            dfs(i);

    for(auto i:ord){
        for(auto v:adj[i])
            answ[i]+=answ[v];
        if(adj[i].size()==0)
            answ[i] += ((char) (i+'a'));
    }
        
    cin >> t >> s;

    string resp = "";
    for(auto c:s){
        if(!poss[c-'a']){
            resp = "-1";
        }
    }

    if(resp=="-1")
        cout << resp <<'\n';
    else{
        for(auto c:s)
            resp += answ[c-'a'];
        cout << resp <<'\n';
    }
    return 0;   
}
