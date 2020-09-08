#include<bits/stdc++.h>
#define ld long double 
#define maxn int(3e5+5)
using namespace std;

vector<vector<int>> adj;
int n, d[maxn], f[maxn];
vector<ld> arr, st;

void dfs(int u, int p){
    arr.push_back(0);
    d[u] = arr.size()-1;

    for(auto v:adj[u])
        if(v!=p)
            dfs(v,u);

    f[u] = arr.size()-1;
}

ld build(int p, int l, int r){
    if(l==r)
        return st[p] = arr[l];
    int med = (l+(r-l)/2);
    return st[p] = build(2*p,l,med) + build(2*p+1,med+1,r);
}

ld update(int p, int l, int r, int i, ld v){
    if(l==r){
        return st[p] = v;
    }
    int med = (l + (r-l)/2);
    if(i<=med){
        return st[p] = update(2*p,l,med,i,v) + st[2*p+1];
    }
    return st[p] = st[2*p]+update(2*p+1,med+1,r,i,v);
}

ld get(int p, int l, int r, int i, int j){
    if(j<l ||r<i)
        return 0;
    else if(i<=l && r<=j)
        return st[p];
    int med = l + (r-l)/2;
    return get(2*p,l,med,i,j) + get(2*p+1,med+1,r,i,j);
}

int main(){
    int q, t, x, y;
    cout.precision(10);
    cin  >> n; 
    adj.assign(n+1,vector<int>());
    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,-1);
    st.assign(4*n+4,0);
    build(1,0,n-1);
    
    cin >> q;
    while(q--){
        cin >> t >> x >> y;
        if(t==1){
            update(1,0,n-1,d[x],log10(y));
        }
        if(t==2){
            ld answ = get(1,0,n-1,d[x],f[x])-get(1,0,n-1,d[y],f[y]);
            if(answ >= 9)
                cout << 1000000000 << '\n';
            else
                cout << fixed << pow((ld)10,answ) << '\n';
        }
    }
    
    return 0;
}
