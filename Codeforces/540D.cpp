#include<bits/stdc++.h>
#define N 505
using namespace std;

int main(){
    int n, m, r1, c1, r2, c2;
    char grid[N][N];
    bool poss = false;
    int ng=0;
    pair<int,int> u;
    int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

    cin >> n >> m;
    memset(grid,'X',sizeof(grid));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> grid[i][j];
        }
    }
    cin >> r1 >> c1;
    cin >> r2 >> c2;

    queue<pair<int,int>> q;
    q.push({r1,c1});
    int x, y;

    if(grid[r2][c2]=='.'){
        for(int i=0;i<4;i++){
            if(grid[r2+dx[i]][c2+dy[i]]!='X'){
                ng++;
            }
            if(r2+dx[i]==r1 && c2+dy[i]==c1){
                ng++;
            }
        }
    }

    if(grid[r2][c2]=='X'){
        for(int i=0;i<4;i++){
            if(r2+dx[i]==r1 && c2+dy[i]==c1){
                poss = true;
            }
        }
    }

    while(q.size() && poss==false){
        u = q.front(); q.pop();
        x = u.first;
        y = u.second;
        for(int i=0;i<4;i++){
            if(x+dx[i]==r2 && y+dy[i]==c2){
                poss = true;
                break;
            }   
            if(grid[x+dx[i]][y+dy[i]]!='X'){
                grid[x+dx[i]][y+dy[i]] = 'X';
                q.push({x+dx[i],y+dy[i]});
            }
        }
    }

    if(poss && grid[r2][c2]=='.'){
        poss = (ng>=2);
    }

    cout << ((poss) ? "YES" : "NO") << '\n';

    return 0;
}