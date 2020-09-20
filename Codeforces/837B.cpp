#include<bits/stdc++.h>
#define maxn 200
using namespace std;

int n, m;
char mat[maxn][maxn];
int igual(int x, int y, int lx, int ly){
    for(int i=x;i<lx;i++)
        for(int j=y;j<ly;j++)
            if(mat[x][y]!=mat[i][j])
                return false;
    return mat[x][y];
}

bool testa(int dx, int dy){
    vector<bool> cond(100,false);
    for(int i=0;i<3;i++){
        if(dx==0)
            cond[igual(0, i*dy,n,(i+1)*dy)] = true;
        if(dy==0)
            cond[igual(i*dx, 0,(i+1)*dx,m)] = true;
    }
    return cond['R']&&cond['G']&&cond['B'];
}


int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> mat[i][j];

    if((n%3==0 && testa(n/3,0)) || (m%3==0 && testa(0,m/3)))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}