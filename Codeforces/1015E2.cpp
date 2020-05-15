#include<bits/stdc++.h>
#define N 1003
using namespace std;

int n, m;
char mat[N][N];
int h[N][N], v[N][N];
int best[N][N][4];
bool visited[N][N];

int main(){


    vector<vector<int>> answ;
    bool poss = true;

    cin >> n >> m;
    int size = n*m+1;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = false;
            cin >> mat[i][j];

            h[i][j] = 0;
            v[i][j] = 0;
            best[i][j][0] = 0;
            best[i][j][1] = 0;
            best[i][j][2] = 0;
            best[i][j][3] = 0;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='*'){
                if(i>0 && mat[i-1][j]=='*'){
                    best[i][j][0] = best[i-1][j][0]+1;
                }
                if(j>0 && mat[i][j-1]=='*'){
                    best[i][j][1] = best[i][j-1][1]+1;
                }
            }
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(mat[i][j]=='*'){
                if(i<n-1 && mat[i+1][j]=='*'){
                    best[i][j][2] = best[i+1][j][2]+1;
                }
                if(j<m-1 && mat[i][j+1]=='*'){
                    best[i][j][3] = best[i][j+1][3]+1;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='*'){
                size = best[i][j][0];
                size = min(size,best[i][j][1]);
                size = min(size,best[i][j][2]);
                size = min(size,best[i][j][3]);
                if(size){
                    answ.push_back({i,j,size});
                }
            }
        }
    }

    for(auto p:answ){
        h[p[0]][p[1]-p[2]] += 1;
        if(p[1]+p[2]+1<m){
            h[p[0]][p[1]+p[2]+1] -=1;
        }

        v[p[0]-p[2]][p[1]] += 1;
        if(p[0]+p[2]+1<n){
            v[p[0]+p[2]+1][p[1]] -= 1;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i>0){
                v[i][j] += v[i-1][j];
            }
            if(j>0){
                h[i][j] += h[i][j-1];
            }
        }   
    }
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%2d",v[i][j] || h[i][j]);
        }
        printf("\n");
    }*/

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='*' && h[i][j]==0 && v[i][j]==0){
                poss = false;
            }
        }   
    }


    if(poss){
        cout << answ.size() << '\n';
        for(auto p: answ){
            cout << p[0]+1 << " " << p[1]+1 << " " << p[2] << '\n';
        }
    }
    else{
        cout << -1 << '\n';
    }


    return 0;
}