#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define maxn int(3e5+5)
#define ll long long
using namespace std;

int n, m, k;
vector<array<ll,3>> updates;
ll ft[maxn];

void clear(){
    memset(ft,0,sizeof(ft));
}

int lsone(int x){
    return x&(-x);
}

void update(int r, ll v){
    for(;r<maxn;r+=lsone(r)){
        ft[r]+=v;
    }
}

void update(int l, int r, ll v){
    if(l<=r)
        update(l,v), update(r+1,-v);
    else
        update(1,r,v), update(l,m,v);
}

ll get(int r){
    ll answ = 0;
    for(;r>0;r-=lsone(r)){
        answ += ft[r];
    }
    return answ;
}

struct Query{
    int id, pos, l, r;
    ll val;

    int getmid(){
        return l + (r-l)/2;
    }
};

vector<Query> queries[maxn];
vector<ll> answ, stations[maxn];

bool ok(int pos, ll val){
    ll acm = 0;
    for(const auto& station:stations[pos]){
        acm += get(station);
        if(acm>=val)
            return 1;
    }
    return acm>=val;
}

void solve(){
    const int LOG = 20;
    answ.assign(n+1,-1);
    for(int iter=0;iter<LOG;iter++){
        clear();
        for(int i=1;i<updates.size();i++){
            update(updates[i][0],updates[i][1],updates[i][2]);
            while(queries[i].size()){
                auto query = queries[i].back(); queries[i].pop_back();
                if(ok(query.pos,query.val)){
                    answ[query.id] = i;
                    query.r = i-1;
                }
                else{
                    query.l = i+1;
                }
                if(query.l<=query.r)
                    queries[query.getmid()].push_back(query);
            }
        }
    }
}

int main(){
    fastio();
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int o;
        cin >> o;
        stations[o].push_back(i);
    }

    vector<ll> o;
    o.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> o[i];
    }

    cin >> k;
    updates.push_back({0,0,0});
    for(int i=0;i<k;i++){
        int a, b, c;
        cin >> a >> b >> c;
        updates.push_back({a,b,c});
    }

    for(int i=1;i<=n;i++){
        ll val = o[i];
        Query query = {i,i,1,k,val};
        queries[query.getmid()].push_back(query);
    }

    solve();

    for(int i=1;i<=n;i++){
        if(answ[i]!=-1)
            cout << answ[i] << "\n";
        else
            cout << "NIE" <<"\n";
    }

    return 0;
}