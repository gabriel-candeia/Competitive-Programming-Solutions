#include<bits/stdc++.h>
#define N 100
#define M 100
using namespace std;

bool func(int mat[N][M], int n, int m){
    map<pair<int,int>,int> edges;
    int l, r;
    for(int j=0, acm=0;j<m;j++){
        acm = 0;
        l = -1;
        for(int i=0;i<n;i++){
            acm+=mat[i][j];
            if(mat[i][j] && l==-1){
                    l  = i;
            }
            else if(mat[i][j]){
                edges[make_pair(l,i)]++;
            }
            if(mat[i][j] && l!=-1 && edges[make_pair(l,i)]>1){
                return false;
            }
        }
        if(acm!=2){
            return false;
        }
    }
    return true;
}

int main(){
    int t, n, m, mat[N][M];
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> mat[i][j];
            }
        }
        cout << ((func(mat,n,m)) ? "Yes\n" : "No\n");
    }
    return 0;
}
