#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define maxn int(1e5+5)
using namespace std;

int n;
ll ft[maxn];

int lsone(int x){
    return x&(-x);
}

void update(int r, ll v){
    for(;r<maxn;r+=lsone(r)){
        ft[r]+=v;
    }
}

ll get(int r){
    if(r<0) return 0;
    ll answ = 0;
    for(;r;r-=lsone(r)){
        answ += ft[r];
    }
    return answ;
}

ll get(int l, int r){
    return get(r)-get(l-1);
}

int main(){
    fastio();
    int n, it =0;
    while(cin>>n){
        for(int i=0;i<=n;i++)
            ft[i] = 0;
        cout << "Case #" << ++it <<":\n";
        set<int> nonzero;
        ll x;
        for(int i=1;i<=n;i++){
            cin >> x;
            update(i,x);
            if(x!=1)
                nonzero.insert(i);
        }

        int m;
        cin >> m;
        while(m--){
            int op, l, r;
            cin >> op >> l >> r;
            if(l>r) swap(l,r);
            if(op==0){
                vector<std::set<int>::iterator> removed;
                auto it = nonzero.lower_bound(l);
                for(;it!=nonzero.end() && (*it)<=r;it++){
                    ll val = get((*it),(*it)), novo = sqrt(val);
                    update((*it),novo-val);
                    if(novo==1)
                        removed.push_back(it);
                }
                for(auto x:removed)
                    nonzero.erase(x);
            }
            else{
                cout << get(l,r) <<"\n";
            }
        }

        cout << "\n";
    }

    return 0;
}