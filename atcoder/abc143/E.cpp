#include<bits/stdc++.h>
#define maxn 305
#define ll long long
using namespace std;

ll n, m, l, mat[maxn][maxn];
const ll inf = 1e9+5;

void fw(){
    for(int k=0;k<n;k++){
        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                mat[u][v] = min(mat[u][v],mat[u][k]+mat[k][v]);
            }
        }
    }
}

int main(){

    cin >> n >> m >> l;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            mat[i][j] = ((i==j) ? 0 : l+1);
    
    for(int i=0;i<m;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        mat[b][a] = mat[a][b] = min(mat[a][b],c);
    }

    fw();
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            mat[i][j] = (mat[i][j]>l) ? inf : 1;
    fw();

    int q;
    cin >> q;
    while(q--){
        int s, t;
        cin >> s >> t;
        cout << (mat[s-1][t-1]==inf ? -1 : mat[s-1][t-1]-1) << "\n";
    }

    return 0;
}