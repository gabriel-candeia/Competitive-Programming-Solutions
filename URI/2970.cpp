#include<bits/stdc++.h>
#define N 100
using namespace std;
int mat[2][N];

int brute(int i, int j, int n, int cnt){
    if(cnt==2*n){
        return 1;
    }
    int ret = 0;
    int dir[3] = {-1,0,1,};
    for(int k=0;k<3;k++){
        for(int k1=0;k1<3;k1++){
            if(i+dir[k]>=0 && j+dir[k1]>=0 && i+dir[k]<2 && j+dir[k1]<n && mat[i+dir[k]][j+dir[k1]]==false){
                mat[i+dir[k]][j+dir[k1]] = true;
                ret += brute(i+dir[k],j+dir[k1],n,cnt+1);
                mat[i+dir[k]][j+dir[k1]] = false;
            }
        }
    }
    return ret;
}

void setup(int n){
    for(int i=0;i<n;i++){
        mat[0][i] = false;
        mat[1][i] = false;
    }
}

int brute_wrapper(int n){
    int answ = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            mat[i][j] = true;
            answ += brute(i,j,n,1);
            mat[i][j] = false;
        }
    }
    return answ;
}

int main(){
    int n;

    
    for(int i=1;i<=7;i++){
        setup(i);
        cout << brute_wrapper(i) << '\n';
    }

    return 0;
}