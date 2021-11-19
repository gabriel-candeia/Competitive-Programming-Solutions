#include<bits/stdc++.h>
#define maxn 1000
using namespace std;

int n, m;
char mat[maxn][maxn];
vector<tuple<char,int,int>> answ;
int dx[4]= {1,-1,0,0}, dy[4] = {0,0,1,-1};

bool isok(int i, int j){
    return i>=0 && j>=0 && i<n && j<m;
}

void dfs(int i, int j){
    mat[i][j] = '#';
    
    for(int k=0;k<4;k++){
        if(isok(i+dx[k],j+dy[k]) && mat[i+dx[k]][j+dy[k]]=='.'){
            dfs(i+dx[k],j+dy[k]);
        }
    }
    
    answ.push_back({'D',i,j});
    answ.push_back({'R',i,j});
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
            if(mat[i][j]=='.')
                answ.push_back(tuple<char,int,int>{'B',i,j});
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='.'){
                dfs(i,j);
                answ.pop_back();
                answ.pop_back();
            }
        }
    }
    cout << answ.size() << "\n";
    for(auto [c,i,j]:answ){
        cout << c << " " << i+1 << " " << j+1 <<"\n";
    }

    return 0;
}