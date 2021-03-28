#include<bits/stdc++.h>
#define maxn int(4e5+5)
#define maxm 50
#define ll long long
using namespace std;

struct node{
    ll freq[maxm], inv;

    node(){
        inv = 0;
        memset(freq,0,sizeof(freq));
    }

    node(int i){
        inv = 0;
        memset(freq,0,sizeof(freq));
        freq[i] = 1;
    }
};

node st[maxn];
ll arr[maxn];

node combine(node left, node right){
    node answ;
    ll qtd=0;

    answ.inv = left.inv + right.inv;
    for(int i=1;i<maxm;i++)
        answ.freq[i] = left.freq[i]+right.freq[i];

    for(int i=1;i<maxm;i++){
        answ.inv += left.freq[i]*qtd;
        qtd += right.freq[i];
    }

    return answ;
}

node build(ll p, ll l, ll r){
    if(l==r)
        return st[p] = node(arr[l]);
    ll med = l + (r-l)/2;
    return st[p] = combine(build(2*p,l,med), build(2*p+1,med+1,r));
}

node update(ll p, ll l, ll r, ll i, ll v){
    if(l==r)
        return st[p] = node(v);
    ll med = l + (r-l)/2;
    if(i<=med)
        return st[p] = combine(update(2*p,l,med,i,v), st[2*p+1]);
    return st[p] = combine(st[2*p], update(2*p+1,med+1,r,i,v));
}

node get(ll p, ll l, ll r, ll i, ll j){
    if(j < l || r < i)
        return node(0);
    else if(i<=l && r<=j)
        return st[p];
    ll med = l + (r-l)/2;
    return combine(get(2*p,l,med,i,j), get(2*p+1,med+1,r,i,j));
}

int main(){
    ll n, m, op, x, y;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    build(1,0,n-1);
    for(int i=0;i<m;i++){
        cin >> op >> x >> y;
        if(op==1)
            cout << get(1,0,n-1,x-1,y-1).inv << '\n';
        else
            update(1,0,n-1,x-1,y);
    }
    return 0;
}