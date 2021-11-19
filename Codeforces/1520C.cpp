#include<bits/stdc++.h>
#define maxn 105
using namespace std;

int mat[maxn][maxn];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;

        if(n==2){
            cout << -1 << "\n";
        }
        else{
            int cnt = 0;
            memset(mat,0,sizeof(mat));
            for(int iter=0, i=0, j=0; iter<n*n;iter++){
                if(mat[i][j]!=0)
                    j = (j+1)%n;
                mat[i][j] = ++cnt;
                j = (j+1)%n;
                i = (i+1)%n;
            }

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                    cout << mat[i][j] << " ";
                cout << "\n";
            }
        }
    }
    return 0;
}