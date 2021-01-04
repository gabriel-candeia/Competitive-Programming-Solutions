#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
using namespace std;

ll ft[maxn], arr[maxn];

ll lsone(ll x){
    return (x&(-x));
}

void update(ll r, ll v){
    if(r==0) return;
    for(;r<maxn;r+=lsone(r))
        ft[r]+=v;
}

ll query(ll r){
    ll sum=0;
    for(;r;r-=lsone(r))
        sum+=ft[r];
    return sum;
}

ll query(ll l, ll r){
    return query(r)-query(l-1);
}

int main(){
    fastio();
    ll n, m, q, x, l, r, op;
    string s;
    map<string,ll> mp;
    vector<string> ord;

    cin >> n >> m >> q;
    for(int i=0;i<n;i++){
        cin >> s;
        ord.push_back(s);
    }

    for(int i=0;i<m;i++){
        cin >> s >> x;
        mp[s] = x;
    }

    for(int i=1;i<=n;i++){
        arr[i] = mp[ord[i-1]];
        update(i,arr[i]);
    }

    for(int i=0;i<q;i++){
        cin >> op;
        if(op==1){
            cin >> l >> s;
            update(l,mp[s]-arr[l]);
            arr[l] = mp[s];
        }
        else{
            cin >> l >> r;
            x = query(l,r);
            if(2*x>(r-l+1)*60){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}