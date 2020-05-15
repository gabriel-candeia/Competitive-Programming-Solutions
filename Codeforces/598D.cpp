#include<bits/stdc++.h>
#define N 1003
using namespace std;

int main(){
    int n, m, k, cnt=0;
    int a, b;
    char grid[N][N];
    int cc[N][N], count[N];
    queue<pair<int,int>> q;
    pair<int,int> u;

    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        count[i] = 0;
        for(int j=1;j<=m;j++){
            cin >> grid[i][j];
            cc[i][j] = 0;
        }
    }
    count[0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(grid[i][j]=='.'){
                grid[i][j] = '#';
                cc[i][j] = ++cnt;
                count[cnt] = 0;
                q.push({i,j});  
                while(q.size()){
                    u = q.front(); q.pop();
                    cc[u.first][u.second] = cnt;

                    if(u.first>1 && grid[u.first-1][u.second]=='.'){
                        grid[u.first-1][u.second] = '#';
                        q.push({u.first-1,u.second});
                    }
                    else if(u.first>1 && grid[u.first-1][u.second]=='*'){
                        count[cnt]++;
                    }

                    if(u.first<n && grid[u.first+1][u.second]=='.'){
                        grid[u.first+1][u.second] = '#';
                        q.push({u.first+1,u.second});
                    }
                    else if(u.first<n && grid[u.first+1][u.second]=='*'){
                        count[cnt]++;
                    }

                    if(u.second>1 && grid[u.first][u.second-1]=='.'){
                        grid[u.first][u.second-1] = '#';
                        q.push({u.first,u.second-1});
                    }
                    else if(u.second>1 && grid[u.first][u.second-1]=='*'){
                        count[cnt]++;
                    }

                    if(u.second<m && grid[u.first][u.second+1]=='.'){
                        grid[u.first][u.second+1] = '#';
                        q.push({u.first,u.second+1});
                    }
                    else if(u.second<m && grid[u.first][u.second+1]=='*'){
                        count[cnt]++;
                    }
                }
            }
        }
    }


    for(int i=0;i<k;i++){
        cin >> a >> b;
        cout << count[cc[a][b]] << '\n';
    }

    return 0;
}