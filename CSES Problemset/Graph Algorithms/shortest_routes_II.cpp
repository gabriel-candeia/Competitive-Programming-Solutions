#include<bits/stdc++.h>
#define maxn 505
#define ll long long
using namespace std;

const ll inf = 1e18;
ll dist[maxn][maxn], n, m;

int main(){
    ll q, a, b, c;

    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
            dist[i][j] = (i!=j)*inf;

    cin >> n >> m >> q;
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = min(c,dist[a][b]);
    }

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i][j] = min(dist[i][k]+dist[k][j],dist[i][j]);

    for(int i=0;i<q;i++){
        cin >> a >> b;
        cout << ((dist[a][b]==inf) ? -1 : dist[a][b]) << "\n";
    }

    return 0;
}