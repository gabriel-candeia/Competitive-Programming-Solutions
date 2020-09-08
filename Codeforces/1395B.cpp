#include<bits/stdc++.h>
#define ll long long
#define N 105
using namespace std;

int grid[N][N], cnt=0;
int n, m, x, y;
vector<pair<int,int>> pos;

int main(){
    
    cin >> n >> m >> x >> y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            grid[i][j] = 0;
        }
    }
    while(cnt<n*m){
        if(grid[x][y]==0){
            grid[x][y] = ++cnt;
            pos.push_back({x,y});
        }
        int next = (y)%m+1; 
        if(grid[x][next]==0){
            y = next;
        }
        else{
            x = (x)%n+1;
        }
    }

    for(auto p:pos){
        cout << p.first << " " << p.second << "\n";
    }
    
    return 0;
}