#include<bits/stdc++.h>
#define ll long long
#define maxn 105
using namespace std;

const ll inf = 1e12;
ll dist[maxn][maxn], n, m, q;

int main(){
    int cnt = 0;
    while(cin >> n >> m){
        if(n==0 && m==0) break;
        for(int i=0;i<maxn;i++)
            for(int j=0;j<maxn;j++)
                dist[i][j] = inf*(i!=j);
        

        ll x, y, w;
        for(int i=0;i<m;i++){
            cin >> x >> y >> w;
            dist[x][y] = dist[y][x] = min(dist[x][y],w);
        }

        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    dist[i][j] = min(dist[i][j],max(dist[i][k],dist[k][j]));

        cout << "Instancia " << ++cnt <<'\n';    
        cin >> q;
        for(int i=0;i<q;i++){
            cin >> x >> y;
            if(x==y)
                cout << 0 <<'\n';
            else
                cout << dist[x][y] <<'\n';
        }
        cout <<'\n';
    }

    return 0;
}