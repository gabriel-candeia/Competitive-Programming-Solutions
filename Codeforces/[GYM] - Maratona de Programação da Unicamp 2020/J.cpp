#include<bits/stdc++.h>
#define maxn 12
using namespace std;

int grid[maxn][maxn];

int func(int x, int y){
    if(x<=0 || y<=0 || x>8 || y>9 || grid[x][y]==1)
        return -10000;
    int dx[4] = {1,1,-1,-1}, dy[4] = {-1,1,+1,-1}, answ = 0;
    for(int i=0;i<4;i++){
        if(grid[x+dx[i]][y+dy[i]]==1){
            grid[x+dx[i]][y+dy[i]]=0;
            answ = max(answ,1+func(x+2*dx[i],y+2*dy[i]));
            grid[x+dx[i]][y+dy[i]]=1;
        }
    }
    return answ;
}


int main(){
    int n, x, y, a, b;

    cin >> n >> x >> y;
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
            grid[i][j] = (j==0 || i==0 || j>8 || i>8);

    for(int i=0;i<n;i++){
        cin >> a >> b;
        grid[a][b]=1;
    }
    cout << func(x,y) <<'\n';
    return 0;
}