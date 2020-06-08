#include<bits/stdc++.h>
#define N 100
using namespace std;

int main(){
    int t, n, m;
    char grid[N][N];
    bool visited[N][N];

    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=m+1;j++){
                grid[i][j] = '#';
                visited[i][j] = false;
            }
        }

        int cnt= 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> grid[i][j];
                cnt += (grid[i][j]=='G');
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(grid[i][j]=='B'){
                    if(grid[i-1][j]!='B'){
                        grid[i-1][j]= '#';
                    } 
                    if(grid[i+1][j]!='B'){
                        grid[i+1][j]= '#';
                    } 
                    if(grid[i][j-1]!='B'){
                        grid[i][j-1]= '#';
                    } 
                    if(grid[i][j+1]!='B'){
                        grid[i][j+1]= '#';
                    } 
                    
                }
            }
        }

        int escaped=0;
        queue<pair<int,int>> q;
        if(grid[n][m]!='#'){
            q.push({n,m});
            visited[n][m] = true;
        }
        pair<int,int> u;

        while(q.size()){
            u = q.front(); q.pop();
            int i= u.first, j = u.second;
            if(grid[i][j]=='G'){
                escaped++;
            }
            if(!visited[i+1][j] && grid[i+1][j]!='#'){
                q.push({i+1,j});
                visited[i+1][j] = true;
            }

            if(!visited[i-1][j] && grid[i-1][j]!='#'){
                q.push({i-1,j});
                visited[i-1][j] = true;
            }

            if(!visited[i][j+1] && grid[i][j+1]!='#'){
                q.push({i,j+1});
                visited[i][j+1] = true;
            }

            if(!visited[i][j-1] && grid[i][j-1]!='#'){
                q.push({i,j-1});
                visited[i][j-1] = true;
            }
        }

        if(escaped==cnt && grid[n][m]!='B'){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }

    }
    return 0;
}