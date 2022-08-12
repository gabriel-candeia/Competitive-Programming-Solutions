#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define maxn 1003
using namespace std;

int n, m;
char mat[maxn][maxn];
int dist[maxn][maxn];
int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};

bool isok(int x, int y){
    return x>=0 && y>=0 && x<n && y<m;
}

int main(){
    fastio();
    int t;

    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> mat[i][j];
                dist[i][j] = -1;
            }
        }

        deque<pair<int,int>> q;
        dist[0][0] = 0, q.push_back({0,0});

        while(q.size()){
            int i, j;
            tie(i,j)  = q.front(); q.pop_front();
            if(mat[i][j]=='#') continue;
            for(int k=0;k<4;k++){
                int x = i + dx[k], y = j+dy[k];
                if(!isok(x,y) || mat[x][y]=='#') continue;
                int d = dist[i][j] + (mat[i][j]!=mat[x][y]);
                if(dist[x][y]==-1 || d<dist[x][y]){
                    if(mat[i][j]==mat[x][y]){
                        dist[x][y] = d;
                        q.push_front({x,y});
                    }
                    else{
                        dist[x][y] = d;
                        q.push_back({x,y});
                    }
                }
            }
            mat[i][j] = '#';
        }        

        cout << dist[n-1][m-1] <<"\n";
        /*cout << dist[4][3] <<"\n";
        cout << mat[4][3] <<"\n";
        cout << mat[4][4] <<"\n";*/
    }

    return 0;
}