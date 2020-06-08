#include<bits/stdc++.h>
#define N 50
using namespace std;

int main(){
    int mat[N][N];
    int row[N], col[N];
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<n;i++){
            row[i] = 0;
        }
        for(int i=0;i<m;i++){
            col[i] = 0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> mat[i][j];
                if(mat[i][j]){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        int acm1=0, acm2=0;
        for(int i=0;i<n;i++){
            acm1+=(row[i]==0);
        }
        for(int i=0;i<m;i++){
            acm2+=(col[i]==0);
        }
        //cout << acm1 << " " << acm2 << '\n';
        cout << ((min(acm1,acm2)%2) ? "Ashish" : "Vivek") << '\n';
    }

    return 0;
}