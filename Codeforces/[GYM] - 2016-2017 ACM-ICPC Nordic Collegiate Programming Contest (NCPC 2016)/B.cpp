#include<bits/stdc++.h>
#define maxn 26
using namespace std;

struct noh{
    int next[maxn], tab, peso=0;
    int dist = -1, parent=0;

    noh(int p=0){
        memset(next,-1,sizeof(next));
        parent = p;
    }
};

vector<noh> t;

void addString(const string& s, int peso){
    if(t.size()==0) t.push_back(noh());
    int curr = 0;
    for(auto c:s){
        if(t[curr].next[c-'a']==-1){
            t[curr].next[c-'a'] = t.size();
            t.push_back(noh(curr));
        }
        curr = t[curr].next[c-'a'];
    }
    t[curr].peso = peso;
}

void dfs(int u){
    for(int i=0;i<maxn;i++){
        int v = t[u].next[i];
        if(v!=-1){
            dfs(v);
            if(t[t[v].tab].peso > t[t[u].tab].peso)
                t[u].tab = t[v].tab;
        }
    }
    if(t[u].peso > t[t[u].tab].peso)
        t[u].tab = u;
}


void bfs(){
    int u;
    queue<int> q;
    q.push(0);
    t[0].dist = 0;
    
    while(q.size()){
        u = q.front(), q.pop();
        for(int i=0;i<maxn;i++){
            int v = t[u].next[i];
            if(v!=-1 && t[v].dist==-1){
                t[v].dist = t[u].dist+1;
                q.push(v);
            }
        }
        int v = t[u].tab;
        if(v!=-1 && t[v].dist==-1){
            t[v].dist = t[u].dist+1;
            q.push(v);
        }
        v = t[u].parent;
        if(v!=-1 && t[v].dist==-1){
            t[v].dist = t[u].dist+1;
            q.push(v);
        }
    }
}

int main(){
    int n, m;

    cin >> n >> m;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        addString(s,n-i);
    }
    
    dfs(0);
    t[0].tab = 0;    
    bfs();

    for(int i=0;i<m;i++){
        string s;
        cin >> s;
        int curr = 0, ptr = 0;
        for(auto c:s){
            if(t[curr].next[c-'a']!=-1){
                curr = t[curr].next[c-'a'];
                ptr++;
            }
            else{
                break;
            }
        }
        cout << (t[curr].dist + (int)s.size()-ptr) << '\n';
    }

    return 0;
}