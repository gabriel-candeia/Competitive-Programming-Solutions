#include<bits/stdc++.h>
#define maxn 1005
using namespace std;

char mat[maxn][maxn], parent[maxn][maxn], mv[4] = {'L','R','U','D'};
int n, m, dx[4] = {0 ,0, 1, -1}, dy[4] = {1 ,-1, 0, 0};

bool isok(int i, int j){
    return (i>=0 && j>=0 && i<n && j<m && mat[i][j]!='#');
}

int main(){    
    pair<int,int> first, last;

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
            if(mat[i][j]=='A') first = {i,j};
            if(mat[i][j]=='B') last = {i,j},  mat[i][j] = '#';
        }
    }

    queue<pair<int,int>> q; q.push(last);
    while(q.size()){
        auto u = q.front(); q.pop();
        for(int k=0;k<4;k++){
            if(isok(u.first+dx[k],u.second+dy[k])){
                mat[u.first+dx[k]][u.second+dy[k]] = '#';
                parent[u.first+dx[k]][u.second+dy[k]] = mv[k];
                q.push({u.first+dx[k],u.second+dy[k]});
            }
        }
    }

    string answ = "";
    while(first!=last && parent[first.first][first.second]){
        for(int k=0;k<4;k++){
            if(parent[first.first][first.second]==mv[k]){
                answ += parent[first.first][first.second];
                first.first -= dx[k];
                first.second -= dy[k];
            }
        }
    }

    if(answ.size()){
        cout << "YES\n";
        cout << answ.size() << "\n";
        cout << answ << "\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}