#include<bits/stdc++.h>
#define N 1000
using namespace std;

int main(){
    int n, a, b;
    int mat[N][N];

    cin >> n >> a >> b;
    
    if(a>=2 && b>=2 ||(n==2 && a==1 && b==1) || (n==3 && a==1 && b==1)){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    if(a==1 && b>1){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = (i!=j);
            }    
        }

        for(int i=0;i<n-b+1;i++){
            for(int j=0;j<n-b+1;j++){
                mat[i][j] = 0;
            }    
        }
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = 0;
            }    
        }

        for(int i=0;i<n-a;i++){
            mat[i][i+1] = 1;
            mat[i+1][i] = 1;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << mat[i][j];
        }    
        cout << '\n';
    }

    return 0;
}