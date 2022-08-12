#include<bits/stdc++.h>
#define maxn int(505)
using namespace std;

int color[maxn], cover[maxn];
vector<int> adj[maxn], dag[maxn];

bool swap_free(const string& s1,const string& s2){
    vector<int> pos;
    int n = s1.size();

    for(int i=0;i<n;i++)
        if(s1[i]!=s2[i])
            pos.push_back(i);

    if(pos.size()<2){
        return 0;
    }
    if(pos.size()>2){
        return false;
    }
    return ((s1[pos[0]]==s2[pos[1]]) && (s1[pos[1]]==s2[pos[0]]));
}

pair<int,int> dfs(int u, int p=1){
    color[u] = p;
    pair<int,int> acm = {color[u] == 1,color[u] == 2};
    for(auto v:adj[u]){
        if(color[v]==0){
            auto aux = dfs(v,(color[u]==1 ? 2 : 1));
            acm.first += aux.first;
            acm.second += aux.second;
        }
    }
    return acm;
}

int n, k;
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to : adj[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

void dfsCover(int v){
    cover[v] = 1;
    for(auto u:dag[v]){
        if(cover[u]==0){
            dfsCover(u);
        }
    }
}

int main(){
    vector<string> arr;

    cin >> n;
    arr.push_back("");
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        arr.push_back(s);
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(swap_free(arr[i],arr[j])==true){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }   

    for(int i=1;i<=n;i++){
        if(color[i]==0){
            auto p = dfs(i,1);
            k += p.second;
        }
    }

    mt.assign(n+1,-1);
    for (int v = 1; v <=n; v++) {
        if(color[v]==1){
            used.assign(n, false);
            try_kuhn(v);
        }
    }

    vector<int> unmatched;
    for(int i=1;i<=n;i++){
        if(color[i]==2) continue;
        bool ok = false;
        for(auto v:adj[i]){
            if(mt[v]==i){
                ok = true;
                dag[v].push_back(i);
            }
            else{
                dag[i].push_back(v);
            }
        }
        if(ok==false) unmatched.push_back(i);
    }
    
    for(auto v:unmatched)
        if(cover[v]==0)
            dfsCover(v);

    int answ = 0;
    for(int i=1;i<=n;i++){
        if(((color[i]==1 && cover[i]==0)||(color[i]==2 && cover[i]==1))==false){
            answ++;
        }
    }

    cout << answ <<"\n";

    return 0;
}