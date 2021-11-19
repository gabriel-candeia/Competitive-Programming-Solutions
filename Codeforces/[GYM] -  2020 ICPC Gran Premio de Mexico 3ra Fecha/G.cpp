#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e5+10)

int n;
int g[maxn], a[maxn], b[maxn];
int seg[maxn<<2];

int combine(int a, int b){
    return max(a, b);
}

void update(int node, int l, int r, int pos, int val){
    if(l > pos || r < pos) return; 
    if(l == pos && r == pos){
        seg[node] = val;
        return;
    }
    int mid = (l+r)/2, nxt = 2*node;
    update(nxt, l, mid, pos, val);
    update(nxt+1, mid+1, r, pos, val);
    seg[node] = combine(seg[nxt], seg[nxt+1]);
}

int neutro(){
    return -1;
}

int get(int node, int l, int r, int x, int y){
    if(l > y || r < x) return neutro();
    if(l >= x && r <= y) return seg[node];
    int mid = (l+r)/2, nxt = 2*node;
    return combine(get(nxt, l, mid, x, y), get(nxt+1, mid+1, r, x, y));
}

int main(){ 
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> g[i] >> a[i] >> b[i];
    }

    for(int i=n-1;i>=0;i--){
        int valor = get(1,0,n,min(i+a[i],n),min(i+b[i],n))+g[i];
        update(1,0,n,i,valor);
    }

    cout << seg[1] <<"\n";
    
    return 0;
}