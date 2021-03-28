#include<bits/stdc++.h>
#define maxn int(8e5+5)
#define ll int
using namespace std;

ll st[maxn], answ[maxn], arr[maxn];

ll build(ll p, ll l, ll r){
    if(l==r)
        return st[p] = 0;
    ll med = l + (r-l)/2;
    return st[p] = build(2*p,l,med)+build(2*p+1,med+1,r);
}

ll update(ll p, ll l, ll r, ll i, ll v){
    if(l==r)
        return st[p] += v;
    ll med = l + (r-l)/2;
    if(i<=med)
        return st[p] = update(2*p,l,med,i,v)+st[2*p+1];
    return st[p] = st[2*p]+update(2*p+1,med+1,r,i,v);
}

ll get(ll p, ll l, ll r, ll i, ll j){
    if(j < l || r < i)
        return 0;
    else if(i<=l && r<=j)
        return st[p];
    ll med = l + (r-l)/2;
    return get(2*p,l,med,i,j)+get(2*p+1,med+1,r,i,j);
}

int main(){
    ll n, x;
    map<ll,ll> lst;

    cin >> n;
    build(1,1,2*n);
    for(int i=1;i<=2*n;i++){
        cin >> arr[i];
        if(lst.find(arr[i])==lst.end()){
            lst[arr[i]] = i;
            update(1,1,2*n,lst[arr[i]],1);
        }
        else{
            answ[arr[i]] = get(1,1,2*n,lst[arr[i]]+1,i);
            update(1,1,2*n,lst[arr[i]],-1);
        }
    }

    lst.clear();
    for(int i=2*n;i>=1;i--){
        if(lst.find(arr[i])==lst.end()){
            lst[arr[i]] = i;
            update(1,1,2*n,lst[arr[i]],1);
        }
        else{
            answ[arr[i]] += get(1,1,2*n,i,lst[arr[i]]-1);
            update(1,1,2*n,lst[arr[i]],-1);
        }
    }

    for(int i=1;i<=n;i++)
        cout << answ[i] << " ";
    cout<<'\n';

    return 0;
}