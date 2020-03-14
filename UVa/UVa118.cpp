#include<bits/stdc++.h>
#define N 101
using namespace std;

bool grid[N][N];
int x, y;

int main(){
    int x0, y0;
    char dir, incX, incY;
    bool lost;
    string moves;

    cin >> x >> y;
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            grid[i][j] = false;
        }
    }

    while(cin >> x0 >> y0 >> dir){
        cin >> moves;
        lost = false;
        for(auto i:moves){
            if(i=='R'){
                dir = ((dir=='N') ? 'E' : ((dir=='E') ? 'S' : ((dir=='S') ? 'W' : 'N')));
            }
            else if(i=='L'){
                dir = ((dir=='N') ? 'W' : ((dir=='W') ? 'S' : ((dir=='S') ? 'E' : 'N')));
            }
            else{
                incX = (dir=='E') - (dir=='W');
                incY = (dir=='N') - (dir=='S');
                if(x0+incX<=x && y0+incY<=y && x0+incX>=0 && y0+incY>=0){
                    x0+=incX;
                    y0+=incY;
                }
                else if(grid[x0][y0]==false){
                    lost = true;
                    grid[x0][y0] = true;
                    break;
                }
            }
        }
        cout << x0 << " " << y0 << " " << dir << ((lost) ? " LOST\n" : "\n");
    }

    return 0;
}

