#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
using namespace std;

struct node{
    node *l, *r;
    ll v;

    node(ll x=0){
        l = r = NULL;
        v = x;
    }
};

void build(node *p, ll l, ll r){
    if(l==r){
        p->v = 0;
        return;
    }
    ll med = (l+r)/2;
    p->l = new node();
    p->r = new node();
    build(p->l,l,med);
    build(p->r,med+1,r);
    p->v = p->l->v + p->r->v;
}

void update(node *last, node *current, ll l, ll r, ll i, ll v){
    if(l==r){
        current->v += v;
        return;
    }
    ll med = (l+r)/2;
    if(i<=med){
        current->r = last->r;
        current->l = new node(last->l->v);
        update(last->l,current->l,l,med,i,v);
    }
    else{
        current->l = last->l;
        current->r = new node(last->r->v);
        update(last->r,current->r,med+1,r,i,v);
    }
    current->v = current->l->v + current->r->v;
}

ll get(node *last, node *current, ll x){
    //cout << current->v-last->v <<"\n";
    ll valor = current->v-last->v;
    if(valor<=x)
        return valor;
    if(current->l==NULL)
        return 0;
    ll esq = current->l->v-last->l->v, dir = current->r->v-last->r->v;
    if(esq>x)
        return get(last->l,current->l,x);
    return max(esq,esq+get(last->r,current->r,x-esq));
}

int main(){
    ll n, q;
    vector<ll> arr;
    map<ll,ll> compress;

    cin >> n >> q;
    arr.assign(n+1,0);
    for(ll i=1;i<=n;i++){
        cin >> arr[i];
        compress[arr[i]];
    }

    ll cnt = 0;
    for(auto &p:compress){
        p.second = ++cnt;
    }

    vector<node*> roots;
    roots.push_back(new node());
    build(roots[0],0,maxn);
    for(ll i=1;i<=n;i++){
        roots.push_back(new node());
        update(roots[i-1],roots[i],0,maxn,compress[arr[i]],arr[i]);
    }

    ll lastResult = 0, l , r;
    for(ll i=0;i<q;i++){
        ll x, y, z;
        cin >> x >> y >> z;
        l = 1 + (x+lastResult-1)%n;
        r = 1 + (y+lastResult-1)%n;
        z = z+lastResult;
        //cout << l <<" " << r << " " << z <<"\n";
        lastResult = get(roots[l-1],roots[r],z);
        cout << lastResult <<"\n";
    }

    return 0;
}