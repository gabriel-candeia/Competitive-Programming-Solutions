#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct noh{
  ll sum, qtd;
  noh *l = NULL, *r = NULL;
};

const int inf = 1e9;

noh* merge(noh* a, noh* b){
    if(a==NULL) return b;
    if(b==NULL) return a;
    noh *c = new noh();
    c->sum = a->sum+b->sum;
    c->qtd = a->qtd+b->qtd;
    return c;
}

void update(noh *p, int l, int r, int i, ll inc1, ll inc2){
    if(l==r){
        p->sum += inc1, p->qtd += inc2;
        return;
    }
    int med = l + (r-l)/2;
    if(i<=med){
        if(p->l==NULL) p->l = new noh();
        update(p->l,l,med,i,inc1,inc2);
    }
    else{
        if(p->r==NULL) p->r = new noh();
        update(p->r,med+1,r,i,inc1,inc2);
    }
    noh* x = merge(p->l,p->r);;
    p->sum = x->sum, p->qtd = x->qtd;
}

ll kth(noh *p, int l, int r, int k){
    if(p==NULL)
        return 0;
    ll leftqtd = ((p->r) ? p->r->qtd : 0);
    if(l==r){
        return (k+1)*l;
    }
    int med = l + (r-l)/2;
    if(p->l!=NULL && k<=p->l->qtd)
        return kth(p->l,l,med,k);
    else{
        ll leftsum = ((p->l) ? p->l->sum : 0);
        return kth(p->r,med+1,r,k-leftqtd)+leftsum;
    }
}


int main(){
    int n, k;
    cin >> n >> k;

    vector<pair<ll,ll>> op;
    op.assign(n,{0,0});
    for(auto &p:op)
        cin >> p.first >> p.second;

    noh *root = new noh({0,0});
    ll total = 0, answ = -1e18;
    update(root,-inf,inf,1,1,1);
    update(root,-inf,inf,2,1,1);
    cout << kth(root,-inf,+inf,1) <<"\n";
    /*for(int i=n-1;i>=0;i--){
        if(op[i].first==1){
            ll soma = kth(root,-inf,+inf,k);
            answ = max(answ,op[i].second + total-soma);
            k--;
        }
        else{
            update(root,-inf,inf,op[i].second,op[i].second,1);
        }
        if(k<0)
            break;
    }*/

    cout << answ <<"\n";

    return 0;
}