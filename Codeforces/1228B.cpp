#include<bits/stdc++.h>
#define ll long long
#define N 1003
using namespace std;

int main(){
    int h, w, r, c;
    int grid[N][N];
    const int M = 1000000007;


    cin >> h >> w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            grid[i][j] = -1;
        }
    }


    for(int i=0;i<h;i++){
        cin >> r;
        for(int j=0;j<r;j++){
            grid[i][j] = 1;
        }
        grid[i][r] = 0;
    }

    ll answ = 1;

    for(int i=0;i<w;i++){
        cin >> c;
        for(int j=0;j<c;j++){
            if(grid[j][i]==0){
                answ = 0;
            }
            grid[j][i] = 1;
        }
        if(grid[c][i]==1){
            answ = 0;
        }
        grid[c][i] = 0;
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(grid[i][j]==-1){
                answ = (answ*2)%M;
            }
        }
    }

    cout << answ << '\n';
    return 0;
}