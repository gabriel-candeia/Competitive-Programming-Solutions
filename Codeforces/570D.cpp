#include<bits/stdc++.h>
#define maxn int(5e5+5)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

vector<int> adj[maxn];
vector<pair<int,int>> queries[maxn];
int v[maxn], ht[maxn], n, m, answ[maxn];
vector<vector<int>> dq;

int precodq(int u, int p){
    ht[u] = ((p!=-1) ? ht[p]+1 : 0);
    for(auto w:adj[u]){
        if(w!=p){
            precodq(w,u);
        }
    }
    return v[u];
}

void merge(vector<int> &a, vector<int> &b){
    if(a.size()<b.size()) 
        swap(a,b);
    for(int i=0;i<(int)b.size();i++)
        a[a.size()-i-1] ^= b[b.size()-i-1];
    b.clear();
}

void solve(int u, int p){
    for(auto w:adj[u]){
        if(w!=p){
            solve(w,u);
            merge(dq[u],dq[w]);
        }
    }
    dq[u].push_back(v[u]);
    /*cout << u << " " << ht[u]<<": ";
    for(auto p:dq[u]){
        cout << p <<", ";
    }
    cout<<"\n";*/
    for(auto p:queries[u]){
        if(p.first-ht[u]>=0 && (p.first-ht[u])<(int)dq[u].size()){
            answ[p.second] = __builtin_popcount(dq[u][dq[u].size()-1-p.first+ht[u]])<=1;
        }
        else{
            answ[p.second] = 1;
        }
    }
}

int main(){
    fastio();
    cin >> n >> m;
    for(int i=2;i<=n;i++){
        int p;
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    for(int i=1;i<=n;i++){
        char c;
        cin >> c;
        v[i] = (1<<(c-'a'));
    }

    precodq(1,-1);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        queries[a].push_back({b-1,i});
    }

    dq.assign(n+1,vector<int>());
    solve(1,-1);

    for(int i=0;i<m;i++){
        cout << (answ[i] ? "Yes" : "No") <<"\n";
    }

    return 0;
}