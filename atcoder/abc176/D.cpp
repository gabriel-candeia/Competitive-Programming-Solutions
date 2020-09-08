#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define N 1005
using namespace std;

const int inf = 1e7;
char grid[N][N];
priority_queue<tuple<int,int,int>> q;
int dist[N][N], n, m, cx, cy, dx, dy;

bool isok(int i, int j){
    return (i>=1 && j>=1 && i<=n && j<=m && grid[i][j] != '#');
}

int main(){
    fastio();
    cin >> n >> m;
    cin >> cx >> cy;
    cin >> dx >> dy;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> grid[i][j];
            dist[i][j] = inf;
        }
    }

    dist[cx][cy] = 0;
    q.push({-dist[cx][cy],cx,cy});

    int x, y, d;
    int a[4] = {0,0,1,-1}, b[4] = {1,-1,0,0};
    while(q.size()){
        tie(d,x,y) = q.top(); q.pop();
        d*=-1; 
        
        for(int i=0;i<4;i++){
            if(isok(x+a[i],y+b[i]) && dist[x+a[i]][y+b[i]]>d){
                dist[x+a[i]][y+b[i]] = d;
                q.push({-dist[x+a[i]][y+b[i]],x+a[i],y+b[i]}); 
            }
        }

        for(int i=-2;i<=2;i++){
            for(int j=-2;j<=2;j++){
                if(isok(x+i,y+j) && dist[x+i][y+j]>d+1){
                    dist[x+i][y+j] = d+1;
                    q.push({-dist[x+i][y+j],x+i,y+j});
                }
            }
        }
        
    }
    
    if(dist[dx][dy]==inf)
        dist[dx][dy] = -1;

    cout << dist[dx][dy] <<'\n';

    return 0;
}