#include<bits/stdc++.h>
#define N 512
using namespace std;

int grid[N][N];

int main(){
    int n, m;
    vector<int> a, b;
    cin >> n >> m;
    a.assign(n,0);
    b.assign(m,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }

    grid[0][0] = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<N;j++)
            if(grid[i][j])
                for(int k=0;k<m;k++)
                    grid[i+1][j|(a[i]&b[k])]=1;        
    }
    int answ = 0;
    for(;grid[n][answ]==0;answ++);
    cout <<answ <<'\n';

}