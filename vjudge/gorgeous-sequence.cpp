#include<bits/stdc++.h>
#define maxn int(4e6+20)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ll long long
using namespace std;
const ll inf = 1e17;

struct node{
    ll sum, lazy;
    int mx1, mx2, f1, f2;

    node(ll x=0){
        sum = mx1 = x, f1 = 1;
        mx2 = -1, f2 = 0;
        lazy = inf;
    }

    node(const node& l, const node& r){
        sum = l.sum + r.sum, lazy = inf;
        if (l.mx1 < r.mx1) {
            mx1 = r.mx1, f1 = r.f1;
            mx2 = max(l.mx1, r.mx2);
        } else if (l.mx1 > r.mx1) {
            mx1 = l.mx1, f1 = l.f1;
            mx2 = max(r.mx1, l.mx2);
        } else {
            mx1 = l.mx1, f1 = l.f1+r.f1;
            mx2 = max(l.mx2, r.mx2);
        }
    }

    void setmin(ll v){
        if(v>=mx1) return;
        sum += (v-mx1)*1ll*f1;    
        mx1 = v;
    }
};

ll n, arr[maxn], m;
node st[maxn];

void pushdown(int p, int l, int r){
    if(st[p].lazy == inf) return;
    st[p].setmin(st[p].lazy);
    if(l!=r){
        st[2*p].lazy = min(st[2*p].lazy,st[p].lazy);
        st[2*p+1].lazy = min(st[2*p+1].lazy,st[p].lazy);
    }
    st[p].lazy = inf;
}

node build(int p, int l, int r){
    if(l==r)
        return st[p] = node(arr[l]);
    int med = (l+r)/2;
    return st[p] = node(build(2*p,l,med),build(2*p+1,med+1,r));
}

node range_set_min(int p, int l, int r, int i, int j, int v){
    pushdown(p,l,r);
    if(j<l || i>r || st[p].mx1<=v)
        return st[p];
    if(i<=l && r<=j && st[p].mx2<v){
        st[p].lazy = min(st[p].lazy,(ll)v);
        pushdown(p,l,r);
        return st[p];
    }
    int med = (l+r)/2;
    return st[p] = node(range_set_min(2*p,l,med,i,j,v), range_set_min(2*p+1,med+1,r,i,j,v));
}

ll range_query_maximum(int p, int l, int r, int i, int j){
    pushdown(p,l,r);
    if(j<l || i>r)
        return -inf;
    if(i<=l && r<=j)
        return st[p].mx1;
    ll med = (l+r)/2;
    return max(range_query_maximum(2*p,l,med,i,j),range_query_maximum(2*p+1,med+1,r,i,j));
}

ll range_query_sum(int p, int l, int r, int i, int j){
    pushdown(p,l,r);
    if(j<l || i>r)
        return 0;
    if(i<=l && r<=j)
        return st[p].sum;
    ll med = (l+r)/2;
    return range_query_sum(2*p,l,med,i,j) + range_query_sum(2*p+1,med+1,r,i,j);
}

int main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<n;i++)
            cin >> arr[i];
        build(1,0,n-1);
        int op, x, y, t;
        for(int i=0;i<m;i++){
            cin >> op >> x >> y;
            if(op==0){
                cin >> t, range_set_min(1,0,n-1,x-1,y-1,t);
            }
            else if(op==1){
                cout << range_query_maximum(1,0,n-1,x-1,y-1) << "\n";
            }
            else{
                cout << range_query_sum(1,0,n-1,x-1,y-1) << "\n";
            }
        }
    }


    return 0;
}