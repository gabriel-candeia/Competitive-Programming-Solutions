#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define block 500
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

struct query{
    int l, r, id, k;

    query(int a, int b, int x, int y){
        l = a, r = b, id = x, k = y;
    }

    bool operator<(const query b){
        return pair<int,int>{l/block,r} < pair<int,int>{b.l/block,b.r};
    }
};

int n, m;
vector<int> arr, fst, lst, adj[maxn], wt;

void dfs(int u, int p){
    fst[u] = arr.size();
    arr.push_back(u);

    for(auto v:adj[u])
        if(v!=p)
            dfs(v,u);

    lst[u] = arr.size()-1;
}

int cnt[maxn], suff[maxn];

void add(int x){
    x = arr[x];
    cnt[wt[x]]++;
    suff[cnt[wt[x]]]++;
    /*
        This may seem wrong, but, since we do not remove 1 from suff[cnt[wt[x]]-1]
        then x is still counted in suff[cnt[wt[x]]-1], suff[cnt[wt[x]]-2] ... suff[0].
        Also, since every cnt[wt[x]] starts at 0 we have that at any
        given moment suff[i] = number of values wt[x] such that cnt[wt[x]]>=i;
    */
}

void remove(int x){
    x = arr[x];
    suff[cnt[wt[x]]]--;
    cnt[wt[x]]--;
}

int main(){
    fastio();
    cin >> n >> m;
    wt.assign(n+1,0);
    for(int i=1;i<=n;i++)
        cin >> wt[i];

    for(int i=0,x,y;i<n-1;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    fst.assign(n+1,0), lst.assign(n+1,0);
    dfs(1,-1);

    vector<query> queries;
    vector<int> answ(m,0);
    for(int i=0, x, k;i<m;i++){
        cin >> x >> k;
        queries.push_back(query(fst[x],lst[x],i,k));
    }

    vector<int> freq(maxn+5,0);
    sort(queries.begin(),queries.end());
        
    int l = 0, r = -1;
    for(auto q:queries){
        while(r<q.r)
            add(++r);
        while(q.l<l)
            add(--l);
        while(l<q.l)
            remove(l++);
        while(q.r<r)
            remove(r--);
        answ[q.id] = suff[q.k];
    }

    for(auto &x:answ)
        cout << x << "\n";

    return 0;
}