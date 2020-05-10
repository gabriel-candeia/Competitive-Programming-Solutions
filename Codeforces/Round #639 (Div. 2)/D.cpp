#include<bits/stdc++.h>
#define N 1003
using namespace std;

int main(){
    int n, m;
    char mat[N][N];
    int lin[N], col[N];
    bool exist = false;

    cin >> n >> m;
    for(int i=0;i<n;i++){
        lin[i] = 0;
        for(int j=0;j<m;j++){
            col[j] = 0;
            cin >> mat[i][j];
            if(mat[i][j]=='#'){
                exist  = true;
            }
        }   
    }

    bool poss = true;
    for(int i=0;i<n;i++){
        int last = -1;
        for(int j=0;j<m;j++){
            if(last!=-1 && j-last>1 && mat[i][j]=='#'){
                poss = false;
            }
            if(mat[i][j]=='#'){
                last = j;
            }
        }
    }

    for(int i=0;i<m;i++){
        int last = -1;
        for(int j=0;j<n;j++){
            if(last!=-1 && j-last>1 && mat[j][i]=='#'){
                poss = false;
            }
            if(mat[j][i]=='#'){
                last = j;
            }
        }
    }

    if(poss || !exist){
        int cnt = 0;
        bool visited[N][N];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visited[i][j] = false;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='#' && !visited[i][j]){
                    cnt++;
                    queue<pair<int,int>> q;
                    pair<int,int> u;
                    q.push({i,j});
                    mat[i][j] = '.';
                    while(q.size()){
                        u = q.front(); q.pop();
                        lin[u.first]++;
                        col[u.second]++;
                        if(u.first+1<n && mat[u.first+1][u.second]=='#'){
                            q.push({u.first+1,u.second});
                            mat[u.first+1][u.second] = '.';
                        }
                        if(u.second+1<m && mat[u.first][u.second+1]=='#'){
                            q.push({u.first,u.second+1});
                            mat[u.first][u.second+1] = '.';
                        }
                        if(u.first-1>=0 && mat[u.first-1][u.second]=='#'){
                            q.push({u.first-1,u.second});
                            mat[u.first-1][u.second] = '.';
                        }
                        if(u.second-1>=0 && mat[u.first][u.second-1]=='#'){
                            q.push({u.first,u.second-1});
                            mat[u.first][u.second-1] = '.';
                        }
                    }
                }
            }
        }
        int zeroLine=0,zeroCol=0;
        for(int i=0;i<n;i++){
            zeroLine += (lin[i]==0);
        }
        for(int i=0;i<m;i++){
            zeroCol += (col[i]==0);
        }
        if(zeroCol==0 && zeroLine!=0 || zeroLine==0 && zeroCol!=0){
            poss = false;
        }
        if(poss){
            cout << cnt << '\n';
        }
        else{
            cout << -1 << '\n';     
        }
    }
    else{
        cout << -1 << '\n';
    }
    return 0;
}