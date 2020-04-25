#include<bits/stdc++.h>
#define N 2000+3
using namespace std;
int mat[N][N], a[N];

int main(){
    int n, h, l, r;

    cin >> n >> h >> l >> r;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=h;j++){
            mat[i][j] = -1;
        }    
    }
    mat[0][0] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<h;j++){
            if(mat[i][j]>=0){
                int temp = (j+a[i])%h;
                mat[i+1][(j+a[i])%h] = max(mat[i+1][(j+a[i])%h],mat[i][j]+(l<=temp && temp<=r));
                temp = (j+a[i]-1)%h;
                mat[i+1][temp] = max(mat[i+1][temp],mat[i][j]+(l<=temp && temp<=r));
            }
        }    
    }

    int answ = 0;
    for(int i=0;i<h;i++){
        answ = max(answ,mat[n][i]);
    }
    /*
    for(int i=0;i<=n;i++){ 
        cout << a[i] <<": ";
        for(int j=0;j<h;j++){
            if(mat[i][j]>=0){
                printf("+");
            }
            printf("%d ",mat[i][j]);
        }   
        cout << '\n';
    }*/
    cout << answ <<'\n';

    return 0;
}