#include<bits/stdc++.h>
#define maxn int(500)
using namespace std;

vector<int> adj[maxn];
int mat[maxn][maxn];

int main(){
    int n, k;

    cin >> n >> k;

    for(int i=0;i<k;i++){
        int x, y;
        cin >> x >> y;
        mat[x][y] = 1;
        adj[x].push_back(y);
    }

    for(int i=1;i<=n;i++){
        mat[i][i] = 1;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                mat[i][j] = (mat[i][j] || (mat[i][k] && mat[k][j]));
            }
        }
    }



    return 0;
}