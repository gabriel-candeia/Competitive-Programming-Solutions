#include<bits/stdc++.h>
#define N 1000
using namespace std;

int main(){
    int t, n, m, x, y;
    char mat[N][N];

    cin >> t;
    while(t--){
        int cnt=0, answ=0, cntD=0;

        cin >> n >> m >> x >> y;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> mat[i][j];
                cnt+=(mat[i][j]=='.');
            }
        }
        answ = cnt*x;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j<m-1 && mat[i][j]=='.' && mat[i][j+1]=='.'){
                    mat[i][j+1] = '*';
                    cntD+=y;
                }
                else if(mat[i][j]=='.'){
                    cntD+=x;
                }
            }
        }
        cout << min(answ,cntD) << '\n';
    }

    return 0;
}