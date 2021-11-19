#include<bits/stdc++.h>
#define maxn 1005
using namespace std;

char mat[maxn][maxn], parent[maxn][maxn], mv[4] = {'R','L','D','U'};
int alive[maxn][maxn];
int n, m, dx[4] = {0 ,0, 1, -1}, dy[4] = {1 ,-1, 0, 0};

bool isok(int i, int j){
    return (i>=0 && j>=0 && i<n && j<m && mat[i][j]!='#' && mat[i][j]!='b');
}

int main(){    
    pair<int,int> first, last;

    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> mat[i][j];

    queue<pair<int,int>> q;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mat[i][j]=='M') q.push({i,j}), mat[i][j] = 'b';
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mat[i][j]=='A') last = {i,j}, q.push(last), mat[i][j] = 'b';
    alive[last.first][last.second] = true;

    while(q.size()){
        auto u = q.front(); q.pop();
        for(int k=0;k<4;k++){
            if(isok(u.first+dx[k],u.second+dy[k])){
                mat[u.first+dx[k]][u.second+dy[k]] = 'b';
                alive[u.first+dx[k]][u.second+dy[k]] = alive[u.first][u.second];
                parent[u.first+dx[k]][u.second+dy[k]] = mv[k];
                q.push({u.first+dx[k],u.second+dy[k]});
            }
        }
    }

    first = {-1,-1};
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if((i==n-1 || i==0 || j==m-1 || j==0) && mat[i][j]=='b' && alive[i][j])
                first = {i,j};
    
    string answ = "";
    while(first!=pair<int,int>{-1,-1} && first!=last && parent[first.first][first.second]){
        for(int k=0;k<4;k++){
            if(parent[first.first][first.second]==mv[k]){
                answ += parent[first.first][first.second];
                first.first -= dx[k];
                first.second -= dy[k];
            }
        }
    }
    answ = string(answ.rbegin(),answ.rend());
    if(answ.size() || first==last){
        cout << "YES\n";
        cout << answ.size() << "\n";
        cout << answ << "\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}