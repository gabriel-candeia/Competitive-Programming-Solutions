#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL);
#define maxn int(1e5+5)
using namespace std;

const int inf = 1e8;
int st[4*maxn], lazy[4*maxn];

int build(int p, int l, int r){
    if(l==r)
        return st[p] = 1;
    int med = (l+r)>>1;
    return st[p] = min(build(2*p,l,med),build(2*p+1,med+1,r));
}

void push(int p, int l, int r){
    if(lazy[p]){
        st[p] = lazy[p];
        if(l!=r){
            lazy[2*p] = lazy[p];
            lazy[2*p+1] = lazy[p];
        }
        lazy[p] = 0;
    }
}

int query(int p, int l, int r, int i, int j){
    push(p, l, r);
    if(j<l || r<i)
        return inf;
    else if(i<=l && r<=j)
        return st[p];
    int med = (l+r)>>1;
    return min(query(2*p,l,med,i,j),query(2*p+1,med+1,r,i,j));
}

int update(int p, int l, int r, int i, int j, int v){
    push(p, l, r);
    if(j<l || r<i)
        return st[p];
    else if(i<=l && r<=j){
        lazy[p] = v;
        push(p,l,r);
        return st[p];
    }
    int med = (l+r)>>1;
    return st[p] = min(update(2*p,l,med,i,j,v),update(2*p+1,med+1,r,i,j,v));
}

int main(){
    fastio();
    int n, m; 

    cin >> n >> m;

    build(1,0,n);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        int q1, q2, q3, v;
        q1 = (a!=0) ? query(1,0,n,0,a-1) : inf;
        q2 = query(1,0,n,a,b);
        q3 = (b!=n) ? query(1,0,n,b+1,n) : inf;
        v = min(q2+4,min(q1,q3)+2);
        update(1,0,n,a,b,v);
    }

    cout << query(1,0,n,0,n) <<"\n";

    return 0;
}