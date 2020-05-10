#include<bits/stdc++.h>
#define N 52
using namespace std;

int main(){
    int n, r1, c1, r2, c2;
    bool mat[N][N];
    char c;
    vector<pair<int,int>> v1, v2;

    cin >> n;
    cin >> r1 >> c1;
    cin >> r2 >> c2;
    for(int i=0;i<=n;i++){
        mat[0][i] = 1;
        mat[i][0] = 1;
        mat[n+1][i] = 1;
        mat[i][n+1] = 1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> c;
            mat[i][j] = c-'0';
        }
    }

    queue<pair<int,int>> q; q.push({r1,c1});
    pair<int,int> u;

    while(q.size()){
        u = q.front(); q.pop();
        v1.push_back(u);
        if(mat[u.first+1][u.second]==0){
            mat[u.first+1][u.second] = 1;
            q.push({u.first+1,u.second});
        }
        if(mat[u.first-1][u.second]==0){
            mat[u.first-1][u.second] = 1;
            q.push({u.first-1,u.second});
        }
        if(mat[u.first][u.second+1]==0){
            mat[u.first][u.second+1] = 1;
            q.push({u.first,u.second+1});
        }
        if(mat[u.first][u.second-1]==0){
            mat[u.first][u.second-1] = 1;
            q.push({u.first,u.second-1});
        }
    }

    q.push({r2,c2});
    while(q.size()){
        u = q.front(); q.pop();
        v2.push_back(u);
        if(mat[u.first+1][u.second]==0){
            mat[u.first+1][u.second] = 1;
            q.push({u.first+1,u.second});
        }
        if(mat[u.first-1][u.second]==0){
            mat[u.first-1][u.second] = 1;
            q.push({u.first-1,u.second});
        }
        if(mat[u.first][u.second+1]==0){
            mat[u.first][u.second+1] = 1;
            q.push({u.first,u.second+1});
        }
        if(mat[u.first][u.second-1]==0){
            mat[u.first][u.second-1] = 1;
            q.push({u.first,u.second-1});
        }
    }
    
    int answ = 1e9;
    for(auto p:v1){
        for(auto k:v2){
            answ = min(answ,(p.first-k.first)*(p.first-k.first)+(p.second-k.second)*(p.second-k.second));
        }
    }

    cout << answ << '\n';

    return 0;
}