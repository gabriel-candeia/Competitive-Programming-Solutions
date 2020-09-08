#include<bits/stdc++.h>
#define N 100
using namespace std;

int mat[N][N];

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin >> mat[i][j];

        bool inv = true;
        int answ=0;
        for(int i=n;i>=2;i--){
            if((mat[1][i]==i)!=inv){
                answ++;
                inv = !inv;
            }
        }

        cout << answ <<'\n';

    }

    return 0;
}