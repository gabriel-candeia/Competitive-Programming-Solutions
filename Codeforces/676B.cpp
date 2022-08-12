#include<bits/stdc++.h>
#define maxn 20
using namespace std;

double mat[maxn][maxn];

int main(){
    int n, t;

    cin >> n >> t;

    mat[0][0] = t;
    int full = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(mat[i][j]>=1){
                mat[i+1][j] += (mat[i][j]-1)*1.0/2;
                mat[i+1][j+1] += (mat[i][j]-1)*1.0/2;
                full++;
            }
        }
    }

    cout << full <<"\n";


    return 0;
} 