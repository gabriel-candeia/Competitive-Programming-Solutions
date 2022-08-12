#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define maxn int(8e5+5)
using namespace std;

ll n;
vector<ll> arr;
queue<pair<ll,ll>> llervals;
pair<ll,ll> st[maxn];
ll lazy[maxn];
const ll inf = 1e16;

pair<ll,ll> build(ll p, ll l, ll r){
    if(l==r){
        lazy[p] = 0;
        return st[p] = {arr[l],l};
    }
    ll med = l + (r-l)/2;
    return st[p] = min(build(2*p,l,med),build(2*p+1,med+1,r));
}

void push(ll p, ll l, ll r){
    st[p].first+=lazy[p];
    if(l!=r){
        lazy[2*p] += lazy[p];
        lazy[2*p+1] += lazy[p];
    }
    lazy[p] = 0;
}

pair<ll,ll> get(ll p, ll l, ll r, ll i, ll j){
    push(p,l,r);
    if(j<l || r<i)
        return {inf,inf};
    if(i<=l && r<=j)
        return st[p];
    ll med = l + (r-l)/2;
    return min(get(2*p,l,med,i,j),get(2*p+1,med+1,r,i,j));
}

pair<ll,ll> update(ll p, ll l, ll r, ll i, ll j, ll x){
    push(p,l,r);
    if(j<l || r<i)
        return st[p];
    if(i<=l && r<=j){
        lazy[p] = x;
        push(p,l,r);
        return st[p];
    }
    ll med = l + (r-l)/2;
    return st[p] = min(update(2*p,l,med,i,j,x),update(2*p+1,med+1,r,i,j,x));
}

int main(){
    fastio();
    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;
    
    ll last = 0;
    ll answ = 0, l, r;
    for(ll i=0;i<n;i++){
        if(arr[i]==0){
            llervals.push({last,i-1});
            last = i+1;
        }
    }
    if(last!=n)
        llervals.push({last,n-1});

    build(1,0,n-1);

    while(llervals.size()){
        ll mn, posmn;
        tie(l,r) = llervals.front(), llervals.pop();
        if(l>r) continue;
        tie(mn,posmn) = get(1,0,n-1,l,r);
        answ+=mn;
        if(l==r) continue;  
        
        vector<ll> pos; 
        pos.push_back(posmn);
        while(true){
            ll x, posx;
            if(pos.back()+1>r)
                break;
            tie(x,posx) = get(1,0,n-1,pos.back()+1,r);
            if(x==mn)
                pos.push_back(posx);
            else    
                break;
        }

        ll last = l;
        pos.push_back(r+1);
        for(auto x:pos){
            if(last<=x-1){
                llervals.push({last,x-1});
            }
            last = x+1;
        }
        update(1,0,n-1,l,r,-mn);
    }

    cout << answ <<"\n";

    return 0;
}