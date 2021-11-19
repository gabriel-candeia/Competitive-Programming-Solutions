#include<bits/stdc++.h>
#define maxn int(3e5+5)
#define ll long long
#define LOG 22
using namespace std;

ll p[maxn][LOG], c[maxn], g[maxn];
int busca(int x){
    if(x==0) return 0;
    ll acm = 0;
    for(int k=LOG-1;k>=0;k--){
        if(p[x][k]!=-1 && g[p[x][k]]>0){
            x = p[x][k], acm += (1<<(k));
        }
    }
    return acm;
}

int lift(int x, int d){
    if(d<0) return -1;
    for(int k=LOG-1;k>=0;k--)
        if(p[x][k]!=-1 && d>=(1<<k))
            x = p[x][k], d-=(1<<k);
    return x;
}


int main(){ 
    ll q, x, y;
    memset(p,-1,sizeof(p));
    
    cin >> q >> x >> y;
    g[0] = x, c[0] = y;
    for(int i=1;i<=q;i++){
        ll op, x, y, z;
        cin >> op;
        if(op==1){
            cin >> x >> y >> z;
            p[i][0] = x, g[i] = y, c[i] = z;
            for(int k=1;k<LOG;k++)
                if(p[i][k-1]!=-1)
                    p[i][k] = p[p[i][k-1]][k-1];
        }
        else{
            cin >> x >> y;
            ll d = busca(x), total=0, custo=0;
            for(ll w = d, u=lift(x,d);w>=0 && y;w--,u=lift(x,w)){
                ll dec = min(y,g[u]);
                
                total += dec;
                custo += dec*c[u];
                g[u] -= dec;
                y -= dec;
            }
            cout << total << " " << custo <<"\n";
        }

    }

    return 0;
}