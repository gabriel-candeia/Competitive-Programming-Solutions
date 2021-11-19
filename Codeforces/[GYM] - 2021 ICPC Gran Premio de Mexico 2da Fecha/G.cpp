#include<bits/stdc++.h>
#define maxn 1005
using namespace std;

char mat[maxn][maxn];
int visited[maxn][maxn];
int n, m;

bool isok(int x, int y){
    return x>=0 && y >= 0 && x<n && y<m;
}

int main(){
    
    vector<vector<pair<int,int>>> pos(26,vector<pair<int,int>>());
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
            pos[mat[i][j]-'A'].push_back({i,j});
        }
    }

    for(int i=0;i<26;i++){
        for(auto p:pos[i]){
            for(int dx=-1;dx<=1;dx++){
                for(int dy=-1;dy<=1;dy++){
                    if(isok(p.first+dx,p.second+dy) && mat[p.first+dx][p.second+dy] == 'A'+i+1){
                        visited[p.first+dx][p.second+dy] = max(visited[p.first+dx][p.second+dy],visited[p.first][p.second]+1);
                    }
                }
            }
        }
    }

    int answ = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            answ = max(answ,visited[i][j]);
        }

    }
    cout << answ+1 << "\n";
    return 0;
}

