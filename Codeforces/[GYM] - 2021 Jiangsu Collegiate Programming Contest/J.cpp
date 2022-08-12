#include<bits/stdc++.h>
#define maxn int(505)
using namespace std;

int n, m;
int mat[maxn][maxn], v[maxn][maxn];
int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
vector<pair<int,int>> aux[2];

bool isok(int x, int y){
    return x>=0 && y>=0 && x<n && y<m;
}

void dfs(int i, int j, bool flag = false){
    v[i][j] = 1;
    aux[flag].push_back({i,j});
    for(int k=0;k<4;k++){
        int x = i+dx[k], y = j+dy[k];
        if(isok(x,y) && v[x][y]==0 && mat[x][y]==mat[i][j]){
            dfs(x,y,!flag);
        }
    }
}

int main(){

    cin >> n >> m;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> mat[i][j];

    vector<pair<int,int>> answ;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==0){
                aux[0].clear(), aux[1].clear();
                dfs(i,j);
                int prox = 0;
                if(aux[1].size()<aux[0].size()) prox = 1;
                answ.insert(answ.end(),aux[prox].begin(),aux[prox].end());
            }
        }
    }

    cout << (answ.size()!=0) << " " << answ.size() <<"\n";
    for(auto p:answ){
        cout << p.first+1 << " " << p.second+1 << " " << 1 << "\n";
    }

    return 0;
}