#include<bits/stdc++.h>
#define N 105
using namespace std;

char grid[N][N];

int main(){
    int n, m, t;
    cin >> t;
    while(t--){
        int answ=0;
        cin >> n >> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> grid[i][j];

                answ+=((i==n-1 && grid[i][j]=='D')||(j==m-1 && grid[i][j]=='R'));
            }
        }
        cout << answ <<'\n';
    }

    return 0;
}