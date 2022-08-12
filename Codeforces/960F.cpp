#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

struct noh{
    int v;
    noh *l, *r;
};

int valor(noh* p){
    return (p ? p->v : 0);
}

int get(noh* p, int l, int r, int i, int j){
    if(!p || j<l || r<i)
        return 0;
    if(i<=l && r<=j)
        return valor(p);
    int med = l + (r-l)/2;
    return max(get(p->l,l,med,i,j),get(p->r,med+1,r,i,j));
}

void update(noh* p, int l, int r, int i, int v){
    if(l==r){
        p->v = v; return;
    }
    int med  = l + (r-l)/2;
    if(i<=med){
        if(p->l==NULL) p->l = new noh();
        update(p->l,l,med,i,v);
        p->v = max(valor(p->l),valor(p->r));
    }
    else{
        if(p->r==NULL) p->r = new noh();
        update(p->r,med+1,r,i,v);
        p->v = max(valor(p->l),valor(p->r));
    }
}

int main(){
    int n, m;
    vector<noh*> st;

    cin >> n >> m;
    for(int i=0;i<=n;i++)
        st.push_back(new noh());
    
    for(int i=0;i<m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        update(st[b],0,maxn,w,get(st[a],0,maxn,0,w-1)+1);
    }

    int answ = 0;
    for(int i=1;i<=n;i++)
        answ = max(answ,st[i]->v);

    cout << answ <<"\n";

    return 0;
}