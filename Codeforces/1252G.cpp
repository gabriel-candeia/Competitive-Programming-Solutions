#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define maxn int(4e5+5)
using namespace std;

vector<int> base;
int st[maxn], lazy[maxn];

int build(int p, int l, int r){
    if(l==r){
        return st[p] = base[l];
    }
    int med = l+(r-l)/2;
    return st[p] = min(build(2*p,l,med),build(2*p+1,med+1,r));
}

void push(int p, int l, int r){
    st[p] += lazy[p];
    if(l!=r){
        lazy[2*p] += lazy[p];
        lazy[2*p+1] += lazy[p];
    }
    lazy[p] = 0;
}

int update(int p, int l, int r, int i, int v){
    push(p,l,r);
    if(r<i){
        return st[p];
    }
    if(i<=l){
        lazy[p] += v;
        push(p,l,r);
        return st[p];
    }
    int med = l + (r-l)/2;
    return st[p] = min(update(2*p,l,med,i,v),update(2*p+1,med+1,r,i,v));
}

int main(){
    fastio();
    int n, m, q, pivot;
    vector<int> arr;
    vector<vector<int>> novos;

    cin >> n >> m >> q;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;
    
    pivot = arr[0];
    int menores = 0;
    for(auto &x:arr)
        menores += (x<pivot);

    for(int i=0;i<m;i++){
        int k;
        cin >> k;
        novos.push_back(vector<int>(k,0));
        menores-=k;
        base.push_back(menores);
        for(auto &x:novos[i]){
            cin >> x;
            menores += (x<pivot);
        }
    }

    
    build(1,0,m-1);
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a!=m && novos[a-1][b-1]<pivot)
            update(1,0,m-1,a,-1);
        novos[a-1][b-1] = c;
        if(a!=m && novos[a-1][b-1]<pivot)
            update(1,0,m-1,a,+1);
        cout << ((st[1]>=0) ? 1 : 0) <<"\n";
    }

    return 0;
}