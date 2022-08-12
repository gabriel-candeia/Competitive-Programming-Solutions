#include<bits/stdc++.h>
#include <sys/resource.h>
#define maxn int(3e5+5)
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

namespace hld{
    int n;
    int sub[maxn], cc[maxn], htcc[maxn], l[maxn], r[maxn], fst[maxn], lst[maxn], t=0, ht[maxn], par[maxn];
    vector<int> adj[maxn], ord;

    void precomp(int u, int p){
        sub[u] = 1;
        for(auto v:adj[u]){
            if(v!=p){
                precomp(v,u);
                sub[u] += sub[v];
            }
        }
    }

    void build(int u, int p, int comp){
        par[u] = p;
        cc[u] = ((comp==-1) ? ++t : comp);
        if(comp==-1) htcc[cc[u]] = ((p!=-1) ? htcc[cc[p]]+1 : 1);
        ht[u] = ((p!=-1) ? ht[p]+1 : 1);

        fst[u] = ord.size();
        if(comp==-1) l[cc[u]] = ord.size();
        r[cc[u]] = ord.size();
        ord.push_back(u);

        int heavy = -1, hsize = 0;
        for(auto v:adj[u]){
            if(v!=p && sub[v] > hsize){
                heavy = v, hsize = sub[v];
            }
        }

        if(heavy!=-1)
            build(heavy,u,cc[u]);

        for(auto v:adj[u]){
            if(v!=p && v!=heavy){
                build(v,u,-1);
            }
        }

        lst[u] = ord.size()-1;
    }
}

struct noh{
    __int128 acmA, acmB, sumHT;

    noh(){
        acmA=0, acmB=0, sumHT=0;  
    }

    noh operator+(const noh& b){
        noh c;
        c.acmA = acmA+b.acmA;
        c.acmB = acmB+b.acmB;
        c.sumHT = sumHT+b.sumHT;
        return c;
    }
};

noh st[4*maxn];
pair<__int128,__int128> lazy[4*maxn];

void push(int p, int l, int r){
    st[p].acmA += lazy[p].first*((__int128)(r-l+1));
    st[p].acmB += lazy[p].second*st[p].sumHT;

    if(l!=r){
        for(int k=0;k<2;k++){
            lazy[2*p+k].first += lazy[p].first;
            lazy[2*p+k].second += lazy[p].second;
        }
    }
    lazy[p] = {0,0};
}

noh build(int p, int l, int r){
    if(l==r){
        st[p].sumHT = hld::ht[hld::ord[l]];
        return st[p];
    }
    int med = (l+r)/2;
    return st[p] = build(2*p,l,med) + build(2*p+1,med+1,r);
}

noh update(int p, int l, int r, int i, int j, const pair<__int128,__int128>& inc){
    push(p,l,r);
    if(j<l || r<i){
        return st[p];
    }
    if(i<=l && r<=j){
        lazy[p].first += inc.first, lazy[p].second += inc.second;
        push(p,l,r);
        return st[p];
    }
    int med = (l+r)/2;
    return st[p] = update(2*p,l,med,i,j,inc) + update(2*p+1,med+1,r,i,j,inc);
}

noh get(int p, int l, int r, int i, int j){
    push(p,l,r);
    if(j<l || r<i){
        return noh();
    }
    if(i<=l && r<=j){
        return st[p];
    }
    int med = (l+r)/2;
    return get(2*p,l,med,i,j) + get(2*p+1,med+1,r,i,j);
}

void update(ll u, __int128 v, __int128 k){
    update(1,0,hld::n-1,hld::fst[u],hld::lst[u],{v-k*hld::ht[u],k});
}

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

__int128 get(int u, int v){
    __int128 answ = 0;
    
    while(hld::cc[u] != hld::cc[v]){
        if(hld::htcc[hld::cc[u]]<hld::htcc[hld::cc[v]]) swap(u,v);
        noh aux = get(1,0,hld::n-1,hld::l[hld::cc[u]],hld::fst[u]);

        /*cout << u << " " << v <<"\n";
        cout << hld::l[hld::cc[u]] << " " << hld::fst[u] <<"\n";
        print(aux.acmA + aux.acmB);
        cout <<"\n";*/

        answ += aux.acmA + aux.acmB;
        u = hld::par[hld::ord[hld::l[hld::cc[u]]]];
    }
    
    if(hld::ht[u]<hld::ht[v]) swap(u,v);
    noh aux = get(1,0,hld::n-1,hld::fst[v],hld::fst[u]);
    answ += aux.acmA + aux.acmB;
    return answ;
}


int main(){
    fastio();
    result = getrlimit(RLIMIT_STACK, &rl);

    cin >> hld::n;
    for(int i=0,a,b;i<hld::n-1;i++){
        cin >> a >> b;
        hld::adj[a].push_back(b);
        hld::adj[b].push_back(a);
    }

    hld::precomp(1,-1);
    hld::build(1,-1,-1);
    build(1,0,hld::n-1);
    
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int op, u, v, k;
        cin >> op;
        if(op==0){
            cin >> u >> v;
            print(get(u,v));
            printf("\n");
        }
        else{
            cin >> u >> v >> k;
            update(u,v,k);
        }   
    }

    return 0;
}