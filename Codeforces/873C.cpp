#include<bits/stdc++.h>
#define N 103
using namespace std;

int n, m, k, mat[N][N];

pair<int,int> best(int j){
    int changes=0, points=0, bp=0, bchanges=0;
    for(int i=1;i<=n;i++){
        if(mat[i][j]==1){
            points = 0;
            for(int l=0;l<min(k,n-i+1);l++){
                points+=mat[i+l][j];
            }
            if(points>bp){
                bp = points;
                bchanges = changes;
            }
            changes++;
        }
    }
    return {bchanges, bp};
}

int main(){
    
    int cntChanges=0, cntPoint=0;
    pair<int,int> u;

    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> mat[i][j];
        }   
    }

    for(int j=1;j<=m;j++){
        u = best(j);
        cntChanges += u.first;
        cntPoint += u.second;
    }

    cout << cntPoint << " " << cntChanges << '\n';

    return 0;
}