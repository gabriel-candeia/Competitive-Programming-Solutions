#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> soma, p, rnk, arr, q;
ll n, mx=0;

void inicializar(){
    soma.assign(n+2,-1);
    rnk.assign(n+2,0);
    p.assign(n+2,0);
    for(int i=0;i<=n+1;i++)
        p[i] = i;
}

void insere(ll i){
    soma[i] = arr[i];
    mx = max(mx,soma[i]);
}

ll find(ll x){
    return ((p[x]==x) ? x : p[x] = find(p[x]));
}

void _union(ll x, ll y){
    x = find(x);
    y = find(y);
    if(x!=y && soma[x]>=0 && soma[y]>=0){
        if(rnk[y]>rnk[x]){
            p[y] = x;
            soma[x]+=soma[y];
        }
        else{
            p[x] = y;
            soma[y]+=soma[x];
            rnk[y] += (rnk[x]==rnk[y]);
        } 
    }
    mx = max({mx,soma[x],soma[y]});
}

int main(){

    cin >> n;
    arr.assign(n+2,0);
    q.assign(n+1,0);
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    for(int i=1;i<=n;i++)
        cin >> q[i];
    inicializar();

    vector<ll> answ;
    answ.assign(n+1,0);

    for(int i=n;i>=1;i--){
        answ[i] = mx;
        insere(q[i]);
        _union(q[i],q[i]-1);
        _union(q[i],q[i]+1);
    }   

    for(int i=1;i<=n;i++){
        cout << answ[i] << "\n";
    }

    return 0;
}