#include<bits/stdc++.h>
#define N 1003
using namespace std;

int n, m;
char mat[N][N];
bool visited[N][N];

int longest_path(int i, int j, int dx, int dy){
    int answ = 0;
    i+=dx;
    j+=dy;
    while(i>=0 && i<n && j>=0 && j<m && mat[i][j]=='*'){
        answ++;
        i+=dx;
        j+=dy;
    }
    return answ;
}


int main(){
    vector<vector<int>> answ;
    bool poss = true;

    cin >> n >> m;
    int size = n*m+1;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = false;
            cin >> mat[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='*'){
                size = n*m+1;
                size = min(size,longest_path(i,j,0,1));
                size = min(size,longest_path(i,j,0,-1));
                size = min(size,longest_path(i,j,1,0));
                size = min(size,longest_path(i,j,-1,0));

                if(size){
                    answ.push_back({i,j,size});

                    for(int k=0;k<=size;k++){
                        visited[i][j+k] = true;
                    }
                    for(int k=0;k<=size;k++){
                        visited[i][j-k] = true;
                    }
                    for(int k=0;k<=size;k++){
                        visited[i-k][j] = true;
                    }
                    for(int k=0;k<=size;k++){
                        visited[i+k][j] = true;
                    }
                }

            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='*' && visited[i][j]==false){
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