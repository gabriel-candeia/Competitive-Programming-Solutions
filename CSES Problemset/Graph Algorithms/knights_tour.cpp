#include<bits/stdc++.h>
#define maxn 8
using namespace std;

int cnt[maxn][maxn], v[maxn][maxn], answ[maxn][maxn];
int dx[2] = {2,1}, dy[2] = {1,2}, mul[2] = {1,-1};

bool isok(int x, int y){
    return x>=0 && y>=0 && x<maxn && y<maxn;
}

int main(){
    int x, y;
    cin >> x >> y;
    x--, y--;
    swap(y,x);
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            for(int m1=0;m1<2;m1++){
                for(int m2=0;m2<2;m2++){
                    for(int k=0;k<2;k++){
                        int x = i + dx[k]*mul[m1], y = j + dy[k]*mul[m2];
                        cnt[i][j] += isok(x,y);
                    }
                }
            }
        }
    }
    
    for(int iter=0;iter<64;iter++){
        int nx=-1, ny=-1, qtd = 10;
        v[x][y] = 1;
        answ[x][y] = iter+1;
        for(int m1=0;m1<2;m1++){
            for(int m2=0;m2<2;m2++){
                for(int k=0;k<2;k++){
                    int tx = x + dx[k]*mul[m1], ty = y + dy[k]*mul[m2];
                    if(isok(tx,ty)){ 
                        cnt[tx][ty]--;
                        if(cnt[tx][ty] < qtd && v[tx][ty]==0)
                            nx = tx, ny = ty, qtd = cnt[tx][ty];
                    }
                }
            }
        }
        x = nx, y = ny;
        //cout << x << " " << y <<"\n";
    }

    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            cout << answ[i][j] << " ";
        }
        cout<<"\n";
    }

    return 0;
}