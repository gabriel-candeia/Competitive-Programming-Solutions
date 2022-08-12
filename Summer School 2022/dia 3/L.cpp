#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

const ll maxn = 1e9+5;
const ll inf = 1e17;
struct noh{
    ll v, min;
    noh *l, *r;
    noh(){
        l = NULL, r = NULL;
    }
    noh(ll pv, ll pmin){
        l = NULL, r = NULL;
        v = pv, min = pmin;
    }
};

void combine(noh *c, noh *a, noh *b){
    if(a!=NULL && b!=NULL){
        if(a->min < b->min){
            c->v = a->v, c->min = a->min;
        }
        else{
            c->v = b->v, c->min = b->min;
        }
    }
    else if(a!=NULL){
        c->v = a->v, c->min = a->min;
    }
    else{
        c->v = b->v, c->min = b->min;
    }
}

void update(noh *p, ll l, ll r, ll i, ll v){
    if(l==r){
        p->v = i, p->min = v;
        return;
    }
    ll med = l + (r-l)/2;
    if(i<=med){
        if(p->l==NULL) p->l = new noh();
        update(p->l,l,med,i,v);
    }
    else{
        if(p->r==NULL) p->r = new noh();
        update(p->r,med+1,r,i,v);
    }
    combine(p, p->l, p->r);
}

int main(){
    fastio();
    ll n, l, r, c, ini, fim;
    vector<ll> arr;
    cin >> n >> l >> r >> c;
    cin >> ini >> fim;

    ini--, fim--;
    arr.assign(n,0);

    for(auto &x:arr)
        cin >> x;

    map<ll,vector<ll>> separado;
    for(ll i=0;i<n;i++){
        separado[arr[i]].push_back(i);
    }

    noh *raiz = new noh(-1,inf);
    vector<ll> dist(n+1,inf);
    priority_queue<tuple<ll,ll>> pq;
    set<ll> visited;
    dist[ini] = 0;
    pq.push({-dist[ini],ini});

    ll iter = 0;
    ll d, u, daux;
    while(pq.size()){
        tie(d,u) = pq.top(), d = -d;
        daux = raiz->min;
        if(daux<d){
            //cout << daux <<" " << raiz->v << "\n";
            ll cor = raiz->v;
            for(auto p:separado[cor]){
                if(daux<dist[p]){
                    dist[p] = daux;
                    pq.push({-dist[p],p});
                }
            }//cout<<"\n";
            update(raiz,0,maxn,cor,inf);
        }
        else{
            pq.pop();
            if(d > dist[u]) continue;
            if(visited.find(arr[u])==visited.end()){
                update(raiz,0,maxn,arr[u],d+c);
                visited.insert(arr[u]);
            }
            if(u-1>=0 && dist[u-1]>d+l){
                dist[u-1] = d+l;
                pq.push({-dist[u-1],u-1});
            }
            if(u+1<n && dist[u+1]>d+r){
                dist[u+1] = d+r;
                pq.push({-dist[u+1],u+1});
            }
        }
    }

    cout << dist[fim] <<"\n";

    return 0;
}