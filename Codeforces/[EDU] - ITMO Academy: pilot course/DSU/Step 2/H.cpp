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
vector<array<ll,4>> edges;

vector<int> solve(ll s){
    vector<bool> used(m+1,0);
    vector<int> answ;
    sort(edges.rbegin(),edges.rend());
    DSU st(n+1);

    for(int i=0;i<edges.size();i++){
        used[i] = st._union(edges[i][1],edges[i][2]);
    }

    for(int i=edges.size()-1;i>=0;i--){
        if(s>=edges[i][0] && used[i]==false){
            s-=edges[i][0];
            answ.push_back(edges[i][3]);
        }
    }

    return answ;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll s;
    cin >> n >> m >> s;
    for(int i=0;i<m;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c,a,b,i+1});
    }

    auto answ = solve(s);
    cout <<answ.size() <<"\n";
    for(auto x:answ){
        cout << x << " ";
    }
    cout<<"\n";
    return 0;
}
