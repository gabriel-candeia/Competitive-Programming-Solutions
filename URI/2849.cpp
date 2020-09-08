#include<bits/stdc++.h>
#define N int(1e5+3)
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int arr[N];
map<int,int> compress, decompress, cc;

struct node{
    node *l, *r;
    int v;

    node(int x=0){
        l = r = NULL;
        v = x;
    }
};

void build(node *p, int l, int r){
    if(l==r){
        p->v = 0;
        return;
    }
    int med = (l+r)/2;
    p->l = new node();
    p->r = new node();
    build(p->l,l,med);
    build(p->r,med+1,r);
    p->v = p->l->v + p->r->v;
}

void update(node *last, node *current, int l, int r, int i, int v){
    if(l==r){
        current->v += v;
        return;
    }
    int med = (l+r)/2;
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

pair<int,int> get(node *last, node *current, int l, int r ,int k){
    if(l==r){
        return {decompress[l],current->v-last->v};
    }
    int med = (l+r)/2, cmp = current->l->v-last->l->v;
    if(k<=cmp){
        return get(last->l,current->l,l,med,k);
    }
    return get(last->r,current->r,med+1,r,k-cmp);
}



int main(){
    fastIO();
    int n, q, l, r, k, g, d;
    pair<int,int> answ;

    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        compress[arr[i]];
    }

    int cnt=0;
    for(auto& p:compress){
        p.second = cnt;
        decompress[cnt++] = p.first;
    }
    vector<node*> roots;
    roots.push_back(new node());
    build(roots[0],0,n-1);
    for(int i=1;i<=n;i++){
        arr[i] = compress[arr[i]];
        cc[arr[i]]++;
        roots.push_back(new node());
        update(roots[i-1],roots[i],0,n-1,arr[i],1);
    }

    for(int i=0;i<q;i++){
        cin >> l >> r >> k >> g >> d;

        answ = get(roots[l-1],roots[r],0,n-1,k);
        cout << answ.first << " " << answ.second << " " << ((abs(g-answ.second)<abs(d-answ.second)) ? "G" : ((abs(g-answ.second)>abs(d-answ.second)) ? "D" : "E")) << '\n';
    }
    
    return 0;
}