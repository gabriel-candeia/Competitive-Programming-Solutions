#include<bits/stdc++.h>
#define maxn 105
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
using namespace std;

const ll inf = 1e12;
ll dist[maxn][maxn][maxn];

int main(){
    fastio();
    ll n, m, q, x, y, w;

    while(cin >> n >> m){

        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dist[0][i][j] = inf*(i!=j);

        for(int i=0;i<m;i++){
            cin >> x >> y >> w;
            dist[0][x][y] = dist[0][y][x] = min(w,dist[0][y][x]);
        }

        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    dist[k][i][j] = min(dist[k-1][i][j],dist[k-1][i][k]+dist[k-1][j][k]);

        cin >> q;
        for(int i=0;i<q;i++){
            cin >> x >> y >> w;
            if(dist[w][x][y]>=inf)  
                cout << -1 << "\n";
            else
                cout << dist[w][x][y] << "\n";
        }
    }

    return 0;
}