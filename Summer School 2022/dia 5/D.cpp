#include <bits/stdc++.h>
using namespace std;
#define maxn int(3e5+10)
#define ll long long
#define LOG 23


ll cost[maxn], qtd[maxn], acmQtd[maxn], acmCost[maxn];
int parent[maxn][LOG], ht[maxn];

int lift(int u, int x){
    for(int k=LOG-1;k>=0;k--){
        if((1<<k)<=x && parent[u][k]){
            u = parent[u][k];
            x -= (1<<k);
        }
    }
    return u;
}

int main(){
    int q;
    cin >> q >> qtd[0] >> cost[0];

    acmQtd[0] = qtd[0];
    acmCost[0] = qtd[0]*cost[0];
    memset(parent,-1,sizeof(parent));

    for(int iter=1;iter<=q;iter++){
        int op;
        cin >> op;
        if(op==1){
            cin >> parent[iter][0] >> qtd[iter] >> cost[iter];
            ht[iter] = ht[parent[iter][0]]+1;
            for(int k=1;k<LOG;k++)
                if(parent[iter][k-1]!=-1)
                    parent[iter][k] = parent[parent[iter][k-1]][k-1];
        }
        else{
            ll v, w, u, wo;
            cin >> v >> w;
            u = v;
            wo = w;

            for(int k=LOG-1;k>=0;k--){
                if(parent[v][k]!=-1 && qtd[parent[v][k]]>0){
                    v = parent[v][k];
                }
            }
            
            ll answ = 0;
            while(w>0){
                ll d = min(w,qtd[v]);
                answ = answ + d*cost[v];
                qtd[v] -= d;
                w -= d;
                if(v==u) break;
                v = lift(u,ht[u]-ht[v]-1);
            }

            cout <<wo-w << " " << answ << endl;
        }   
    }

	return 0;
}
