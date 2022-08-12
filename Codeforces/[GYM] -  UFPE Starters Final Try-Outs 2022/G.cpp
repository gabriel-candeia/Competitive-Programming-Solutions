#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e5+5)
using namespace std;

struct noh{
    int qtd = 0;
    noh *l, *r;

    noh(){
        l = r = NULL;
    }

    noh(noh *pl, noh *pr){
        l = pl, r = pr;
    }
};

noh *root = new noh();
void update(noh *p, ll bit, ll val){
    if(bit==-1){
        p->qtd++;    
        return;
    }
    ll cmp = val&(1ll<<bit);
    if(cmp){
        if(p->r==NULL) p->r = new noh();
        update(p->r,bit-1,val);
    }
    else{
        if(p->l==NULL) p->l = new noh();
        update(p->l,bit-1,val);
    }   
    p->qtd = ((p->l!=NULL) ? p->l->qtd : 0) + ((p->r!=NULL) ? p->r->qtd : 0);
}

ll get(noh *p, ll bit, ll val){
    if(bit==-1){
        return 0;
    }
    ll cmp = val&(1ll<<bit), inc = (1ll<<bit);
    if(cmp){
        if(p->l!=NULL){
            return inc|get(p->l,bit-1,val);
        }
        return get(p->r,bit-1,val);
    }
    else{
        if(p->r!=NULL){
            return inc|get(p->r,bit-1,val);
        }
        return get(p->l,bit-1,val);
    }
}


vector<pair<int,int>> adj[maxn];
ll dist[maxn];

void dfs(int u, int p){
    for(auto e:adj[u]){
        int v, wt;
        tie(v,wt) = e;
        if(v!=p){
            dist[v] = dist[u]^wt;
            dfs(v,u);
        }
    }
}

int main(){
    int n;
    cin >> n;

    for(int i=2;i<=n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back({i,b});
        adj[i].push_back({a,b});
    }

    dfs(1,-1);
    for(int i=1;i<=n;i++){
        update(root,32,dist[i]);
    }
    
    for(int i=1;i<=n;i++){
        cout << get(root,32,dist[i]) <<"\n";
    }

    return 0;
}
