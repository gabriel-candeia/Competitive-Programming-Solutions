#include<bits/stdc++.h>
#define maxn 105
using namespace std;

char mat[maxn][maxn];

int main(){
    int h, w, x, y;

    cin >> h >> w >> x >> y;
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            cin >> mat[i][j];
    x--, y--;
    int answ = 1;
    for(int i=y+1;i < w && mat[x][i]!='#';i++) answ++;
    for(int i=y-1;i >=0 && mat[x][i]!='#';i--) answ++;
    for(int i=x+1;i < h && mat[i][y]!='#';i++) answ++;
    for(int i=x-1;i >= 0 && mat[i][y]!='#';i--) answ++;
    cout << answ <<'\n';
    return 0;
}