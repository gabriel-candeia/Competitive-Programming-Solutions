#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
using namespace std;

vector<int> adj[maxn];
int dg[maxn], flag[maxn], aux[maxn];


int main(){
    int n, m, x, y;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        dg[x]++;
        dg[y]++;
    }

    for(auto v:adj[1])
        flag[v] = 1;
    
    for(int i=1;i<=n;i++)
        for(auto v:adj[i])
            aux[i] += flag[v];

    ll answ = 0;
    for(auto v:adj[1])
        for(auto u:adj[v])
            if(u!=1) answ+=(aux[u]-1);

    cout << answ <<"\n";
    return 0;
}