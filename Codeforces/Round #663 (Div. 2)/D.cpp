#include<bits/stdc++.h>
#define N 1
using namespace std;

vector<vector<int>> mat;
int n, m, answ = 10;
int alternante(int i, int start){
    int answ =0;
    for(int j=0;j<n;j++){
        answ+=(start!=mat[i][j]);
        start = !start;
    }
    return answ;
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    mat.assign(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    if(n>=4 && m>=4){
        cout << -1 <<"\n";
        return;
    }
    if(n==1 || m==1){
        cout << 0 <<'\n';
        return.
    }
    if(n==2){
        int arr[2] = {0,0};
        for(int i=0;i<m;i++){
            arr[i%2]+=mat[i][0]+mat[i][1];
        }
        cout << min(arr[0],arr[1]) <<'\n';
        return;
    }
    if(m==2){
        int arr[2] = {0,0};
        for(int i=0;i<n;i++){
            arr[i%2]+=mat[0][i]+mat[1][i];
        }
        cout << min(arr[0],arr[1]) <<'\n';
        return;
    }
    if(n==3){
        int arr[2] = {0,0}, centro=0;
        int custo = min(alternante(0,0),alternante(0,1))+min(alternante(1,0),alternante(1,1));
        for(int i=0;i<m;i++){
            centro+=mat[1][i];
        }
        centro = min(centro,m-centro)
    }
    return 0;
}