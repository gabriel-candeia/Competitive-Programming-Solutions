#include<bits/stdc++.h>
#define maxn 500
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int n, m;
int mat[maxn][maxn];

void solve(int sx, int sy, int spower){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(abs(i-sx)+abs(j-sy)<=spower-1){
                mat[i][j] = 0;
            }
        }
    }
}

int main(){

    int qtd = 0;
    cin >> qtd;
    vector<array<int,3>> bombas;
    for(int i=0;i<qtd;i++){
        int a, b, power;
        cin >> power >> a >> b;
        bombas.push_back({b,a,power});
    }

    cin >> n >> m;
    swap(n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin >> c;
            mat[i][j] = c-'0';
        }
    }

    for(int i=0;i<qtd;i++){
        solve(bombas[i][0],bombas[i][1],bombas[i][2]);
    }

    int ones = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ones += mat[i][j];
        }
    }

    cout << ((ones==0) ? "DESTRUIU TUDO!" : "NAO DESTRUIU TUDO!") <<"\n";

    return 0;
}
