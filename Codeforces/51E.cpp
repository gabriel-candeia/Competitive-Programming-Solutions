#include<bits/stdc++.h>
#define maxn int(701)
#define ll long long
using namespace std;

int n, m;
int adj[maxn][maxn], inter[maxn][maxn];

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = 1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(k==i || k==j || i==j) continue;
                inter[i][j] += adj[i][k] && adj[j][k];
            }
        }
    }

    ll answ = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!adj[i][j]) continue;
            for(int k=1;k<=n;k++){
                if(k==i || k==j || i==j) continue;
                answ += (inter[i][k]-adj[j][k])*(inter[j][k]-adj[i][k]);
            }
        }
    }

    cout << answ/10 <<"\n";

    return 0;
}
