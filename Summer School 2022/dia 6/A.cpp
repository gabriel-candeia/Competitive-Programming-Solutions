#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

int n, dist[maxn], p[maxn], onpath[maxn];
vector<int> adj[maxn];
int maior = 0;
vector<int> answ; 

void dfs(int pos, int pai) {
    p[pos] = pai;
    dist[pos] = ((pai!=-1) ? dist[pai]+1 : 0);
    if(dist[pos] > dist[maior])
        maior = pos;
    for(int &i : adj[pos]) 
        if(i != pai) dfs(i,pos);
}

void dfs2(int pos, int pai) {
    dist[pos] = ((pai!=-1) ? dist[pai]+1 : 0);
    if(dist[pos] > dist[maior] && pos!=answ[0] && (answ.size()!=2 || pos!=answ[1]))
        maior = pos;
    for(int &i : adj[pos]) 
        if(i != pai && onpath[i]==0) dfs2(i,pos);
}

int32_t main(){
    cin>>n;
    
    for(int i=0; i<n-1; i++) {
        int a,b;
        cin>>a>>b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    maior = 0;
    dist[maior] = -1;
    dfs(1,-1);

    memset(dist,0,sizeof(dist));
    memset(p,0,sizeof(p));
    dfs(maior,-1);

    answ.push_back(maior);
    int valor = dist[maior];
    memset(dist,0,sizeof(dist));
    int u = maior;
    maior = 0;
    dist[maior] = -1;
    for(int i=u;i!=-1;i=p[i]){
        onpath[i] = 1;
        dist[i] = 0;
        if(p[i]==-1)
            answ.push_back(i);
        else
            dist[p[i]] = -1;
        dfs2(i,p[i]);
        //cout << i << " " << p[i] << " " << maior << "\n";
    }
    answ.push_back(maior);
    valor += dist[maior];
    //cout << dist[7] <<"\n";
    cout << valor <<"\n";
    for(auto x:answ)
        cout << x << " ";
    cout<<"\n";

    return 0;
}