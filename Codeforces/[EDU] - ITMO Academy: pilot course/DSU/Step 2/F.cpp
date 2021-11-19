#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

struct DSU{
    vector<int> parent, rnk;

    DSU(int n){
        parent.assign(n+1,0);
        for(int i=1;i<=n;i++)
            parent[i] = i;
        rnk.assign(n,0);
    }

    int find(int x){
        return (x==parent[x]) ? x : parent[x] = find(parent[x]);
    }

    bool _union(int x, int y){
        x = find(x), y = find(y);
        if(x!=y){
            if(rnk[x]<rnk[y]){
                parent[x] = y;
            }
            else{
                parent[y] = x;
                rnk[x] += (rnk[y]==rnk[x]);
            }
            return true;
        }
        return false;
    }
};

int n, m;
const ll inf = 3e9;
vector<array<ll,3>> edges;

ll solve(int beg){
    vector<bool> used(m+1,0);
    DSU st(n+1);
    ll mn = inf, mx = -inf;
    int selected = 0;

    for(int i=beg;i<edges.size();i++){
        if(st._union(edges[i][1],edges[i][2])){
            selected++;
            mx = max(mx,edges[i][0]);
            mn = min(mn,edges[i][0]);
        }
    }
    if(selected==n-1){
        return mx-mn;
    }
    return inf;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0;i<m;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c,a,b});
    }

    sort(edges.begin(),edges.end());

    ll answ = inf;
    for(int i=0;i<m;i++){
        answ = min(answ,solve(i));
    }
    
    if(answ==inf){
        cout << "NO" <<"\n";
    }
    else{
        cout << "YES" <<"\n";
        cout << answ <<"\n";
    }
    

    return 0;
}
