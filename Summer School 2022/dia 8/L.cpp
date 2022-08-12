#include<bits/stdc++.h>
#define ll long long
#define maxn int(105)
using namespace std;

int n, m;
int mat[maxn][maxn], cor[maxn][maxn];

pair<int,int> centro(int x, int y){
    int preto=0, branco=0;
    for(int i=x-1;i<=x+1;i++){
        for(int j=y-1;j<=y+1;j++){
            if(i>=0 && i<=n+1 && j>=0 && j<=m+1){
                preto += (cor[i][j]==0);
                branco += (cor[i][j]==1);
            }
        }
    }
    return {preto,branco};
}

int main(){
    cin >> n >> m;

    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            cin >> mat[i][j];
        }
    }

    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            cor[i][j] = -1;
        }
    }

    bool ok = true;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            pair<int,int> qtd = centro(i,j);
            if(mat[i][j]-qtd.second<=1 && mat[i][j]-qtd.second>=0){
                cor[i+1][j+1] = mat[i][j]-qtd.second;
            }
            else{
                ok = false;
            }
        }
    }

    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            ok = (ok && (centro(i,j).second==mat[i][j]));
        }
    }

    if(ok==false){
        cout << "impossible\n";
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout << (cor[i][j]==0 ? '.' : 'X');
            }
            cout <<'\n';
        }
    }

    return 0;
}