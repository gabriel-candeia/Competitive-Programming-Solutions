#include<bits/stdc++.h>
#define N int(1e5+3)
#define ll long long
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;


int arr[N];
struct node{
    node *l, *r;
    ll v;

    node(){
        l = r = NULL;
        v = 0;
    }
};

void build(node *p, int l, int r){
    if(l==r){
        p->v = arr[l];
        return;
    }
    int med = l + (r-l)/2;
    p->l = new node();
    p->r = new node();
    build(p->l,l,med);
    build(p->r,med+1,r);
    p->v = p->l->v + p->r->v;
}

ll get(node *p, int l, int r, int i, int j){
    if(j<l || r<i){
        return 0;
    }
    else if(i<=l && r <=j){
        return p->v;
    }
    else{
        int med = l + (r-l)/2;
        return get(p->l,l,med,i,j) + get(p->r,med+1,r,i,j);
    }
}

void update(node* last, node* current, int l, int r, int i, int v){
    if(l==r){
        current->v = v;
        return;
    }
    int med = l + (r-l)/2;
    if(i<=med){
        current->r = last->r;
        current->l = new node();
        update(last->l,current->l,l,med,i,v);
    }
    else{
        current->l = last->l;
        current->r = new node();
        update(last->r,current->r,med+1,r,i,v);
    }
    current->v = current->l->v + current->r->v;
}

int main(){
    int n, t,q;
    fastIO();
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        vector<node*> root;
        root.push_back(new node());
        build(root[0],0,n-1);
        cin >> q;
        int op, x, y, k;
        while(q--){
            cin >> op;
            if(op==1){
                cin >>  x >> y >> k;
                cout << get(root[k],0,n-1,x-1,y-1) << '\n';
            }
            else{
                cin >> x >> k;
                root.push_back(new node());
                update(root[root.size()-2],root[root.size()-1],0,n-1,x-1,k);
            }
        }
    }
    return 0;
}
