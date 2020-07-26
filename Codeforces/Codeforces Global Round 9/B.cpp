#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, m;
    int grid[310][310];
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                grid[i][j] = 4;
            }
        }

        for(int i=1;i<n-1;i++){
            grid[i][0] = 3;
            grid[i][m-1] = 3;
        }

        for(int j=1;j<m-1;j++){
            grid[0][j] = 3;
            grid[n-1][j] = 3;
        }

        grid[0][0] = grid[0][m-1] = grid[n-1][0] = grid[n-1][m-1] = 2;

        bool poss = true;
        int a;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> a;
                poss = poss && (a<=grid[i][j]);
            }
        }

        if(poss){  
            cout << "YES\n";
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout << grid[i][j] << " ";
                }
                cout << '\n';
            }
        }
        else{
            cout << "NO\n";
        }
    }


    return 0;
}