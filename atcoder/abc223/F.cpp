#include<bits/stdc++.h>
#define maxn int(2e5+1)
#define ll long long
using namespace std;

int n, q, st[4*maxn], lazy[4*maxn];
vector<int> pref;

int build(int p, int l, int r){
    if(p==-1)
        exit(-1);
    if(l==r){
        return st[p] = pref[l];
    }
    int med = (l+r)>>1;
    return st[p] = min(build(2*p,l,med),build(2*p+1,med+1,r));
}

void push(int p, int l, int r){
    st[p]+=lazy[p];
    if(l!=r){   
        lazy[2*p] += lazy[p];
        lazy[2*p+1] += lazy[p];
    }
    lazy[p] = 0;
}

int update(int p, int l, int r, int i, int j, int v){
    push(p,l,r);
    if(j<l || r<i){
        return st[p];
    }
    if(i<=l && r<=j){
        lazy[p] += v, push(p,l,r);
        return st[p];
    }
    int med = (l+r)>>1;
    return st[p] = min(update(2*p,l,med,i,j,v),update(2*p+1,med+1,r,i,j,v));
}

const int inf = 5e7;

int query_range(int p, int l, int r, int i, int j){
    push(p,l,r);
    if(j<l || r<i){
        return inf;
    }
    if(i<=l && r<=j){
        return st[p];
    }
    int med = (l+r)>>1;
    return min(query_range(2*p,l,med,i,j),query_range(2*p+1,med+1,r,i,j));
}

int query_ponto(int p, int l, int r, int i){
    push(p,l,r);
    if(l==r){
        return st[p];
    }
    int med = (l+r)>>1;
    if(i<=med){
        return query_ponto(2*p,l,med,i);
    }
    return query_ponto(2*p+1,med+1,r,i);
}

int main(){
    string s;
    cin >> n >> q;
    cin >> s;

    pref.assign(n+1,0);

    for(int i=1;i<=n;i++)
        pref[i] = pref[i-1] + ((s[i-1]=='(') ? 1 : -1);
    
    build(1,0,n);
    
    while(q--){
        int op, a, b;
        cin >> op >> a >> b;
        if(op==1){
            if(s[a-1]!=s[b-1]){
                update(1,0,n,a,b-1,(s[a-1]=='(') ? -2 : 2);
                swap(s[a-1],s[b-1]);
            }
        }
        else{
            int pref = query_ponto(1,0,n,a-1), minimo_range  = query_range(1,0,n,a,b), lst = query_ponto(1,0,n,b);
            if(minimo_range-pref>=0 && lst-pref==0){
                cout << "Yes" << "\n";
            }
            else{
                cout << "No" << "\n";
            }
        }
    }

    return 0;
}