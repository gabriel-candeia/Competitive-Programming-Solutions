#include<bits/stdc++.h>
#define maxn 1500+5
using namespace std;

int grid[maxn][maxn], lin[maxn][maxn], col[maxn][maxn], up[maxn][maxn], last[maxn][maxn], h, w;

int main(){
    int n, m, x, y;
    cin >> h >> w >> n >> m;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        grid[x][y] = 1;
    }

    for(int i=0;i<m;i++){
        cin >> x >> y;
        grid[x][y] = -1;
    }

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(grid[i][j]==-1){
                up[i][j] = i;
                last[i][j] = j;
            }
            else{
                up[i][j] = up[i-1][j];
                last[i][j] = last[i][j-1];
            }
            if(grid[i][j]==1){
                col[up[i][j]+1][j] = 1;
                lin[i][last[i][j]+1] = 1;
            }
        }    
    }

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(grid[i][j]==-1 || grid[i][j-1]==-1)
                continue;
            lin[i][j]+=lin[i][j-1];
        }    
    }
    int answ = 0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(grid[i][j]==-1 || grid[i-1][j]==-1){
                answ += (col[i][j]>0 || lin[i][j]>0);
                continue;
            }
            col[i][j]+=col[i-1][j];
            answ += (col[i][j]>0 || lin[i][j]>0);
        }    
    }
    cout << answ <<'\n';
    return 0;
}