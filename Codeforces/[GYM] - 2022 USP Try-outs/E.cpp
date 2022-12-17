#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define maxm int(1e6+5)
#define maxn int(2e5+5)
#define ll long long
using namespace std;

struct llerval{
    ll first, second; 
    ll val = 0;

    bool operator<(const llerval& o ) const {
        if(first==o.first)
            return second < o.second;
        return first < o.first;
    }
};

namespace tot{
    ll tot[maxm];

    void precomp(){
        tot[0] = 0;
        tot[1] = 1;
        for(ll i = 2; i < maxm; i++)
            tot[i] = i;
        for(ll i = 2; i < maxm; i++){
            if(tot[i] == i){
                for(ll j = i; j < maxm; j += i)
                    tot[j] -= tot[j]/i;
            }
        }
        for(ll i = 1; i < maxm; i++)
            tot[i] = tot[i]-1;
    }
}

namespace seg{
    ll seg[4*maxn], lazy[4*maxn];

    void push(ll node, ll l, ll r){
        if(lazy[node]){
            seg[node] += (r-l+1)*lazy[node];
            if(l != r){
                ll nxt = node<<1;
                lazy[nxt] += lazy[node];
                lazy[nxt+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    
    void update(ll node, ll l, ll r, ll x, ll y, ll val){
        push(node, l, r);
        if(l > y || r < x) return;
        if(l >= x && r <= y){
            lazy[node] += val;
            push(node, l, r);
            return;
        }
        ll mid = (l+r)>>1, nxt = node<<1;
        update(nxt, l, mid, x, y, val);
        update(nxt+1, mid+1, r, x, y, val);
        seg[node] = seg[nxt] + seg[nxt+1];
    }
    
    ll get(ll node, ll l, ll r, ll x, ll y){
        push(node, l, r);
        if(l > y || r < x) return 0;
        if(l >= x && r <= y) return seg[node];
        ll mid = (l+r)>>1, nxt = node<<1;
        return get(nxt, l, mid, x, y) + get(nxt+1, mid+1, r, x, y);
    }
}

int main(){
    fastio();
    ll n, q;
    tot::precomp();

    set<llerval> st;
    cin >> n >> q;

    for(ll i=1;i<=n;i++){
        ll x;
        cin >> x; x--;
        if(x>0){
            st.insert({i,i,x});
            seg::update(1,1,n,i,i,x);
        }
    }

    while(q--){
        ll l, r, op;
        cin >> op;
        if(op==1){
            cin >> l >> r;
            vector<llerval> remove; 
        
            auto iter = (st.upper_bound({l,l}));
            if(iter!=st.begin()) iter--;
            for(;iter!=st.end() && iter->first<=r;iter++){
                remove.push_back(*iter);
            }
            
            if(remove.size() && remove[0].first<l){
                auto& x = remove[0];
                st.erase(x);
                st.insert({l,x.second,x.val});
                if(l-1 >= x.first)
                    st.insert({x.first,l-1,x.val});
                x.first = l;
            }

            if(remove.size() && remove.back().second>r){
                auto& x = remove.back();
                st.erase(x);
                st.insert({x.first,r,x.val});
                if(r+1 <= x.second)
                    st.insert({r+1,x.second,x.val});
                x.second = r;
            }
            
            for(auto x:remove){
                seg::update(1,1,n,x.first,x.second,-x.val);
                st.erase(x);
        
                x.val = tot::tot[x.val+1];
                if(x.val>0){
                    seg::update(1,1,n,x.first,x.second,x.val);
                    st.insert(x);
                }
            }
            
        }
        else if(op==2){
            ll newVal;
            cin >> l >> r >> newVal;
            newVal--;

            vector<llerval> remove; 
            
            auto iter = (st.upper_bound({l,l}));
            if(iter!=st.begin()) iter--;
            for(;iter!=st.end() && iter->first<=r;iter++){
                remove.push_back(*iter);
            }

            if(remove.size() && remove[0].first<l){
                auto& x = remove[0];
                st.erase(x);
                st.insert({l,x.second,x.val});
                if(l-1 >= x.first)
                    st.insert({x.first,l-1,x.val});
                x.first = l;
            }

            if(remove.size() && remove.back().second>r){
                auto& x = remove.back();
                st.erase(x);
                st.insert({x.first,r,x.val});
                if(r+1 <= x.second)
                    st.insert({r+1,x.second,x.val});
                x.second = r;
            }

            for(auto x:remove){
                if(x.val>0)
                    seg::update(1,1,n,x.first,x.second,-x.val);
                st.erase(x);
            }

            if(newVal>0){
                seg::update(1,1,n,l,r,newVal);
                st.insert({l,r,newVal});
            }
        }
        else{
            cin >> l >> r;
            cout << seg::get(1,1,n,l,r) + (r-l+1) <<"\n";
        }
    }

    return 0;
}