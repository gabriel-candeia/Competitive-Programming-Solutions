#include<bits/stdc++.h>
#define maxn int(1e3+5)
using namespace std;

char mat[maxn][maxn];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mat[i][j];
        }
    }
    bool answ = false;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int acm = 0;
            if(i+6<=n){
                acm = 0;
                for(int k=0;k<6;k++){
                    acm += (mat[i+k][j]=='#');
                }
                answ = (answ || acm>=4);
            }
            if(j+6<=n){
                acm = 0;
                for(int k=0;k<6;k++){
                    acm += (mat[i][j+k]=='#');
                }
                answ = (answ || acm>=4);
            }
            if(i+6<=n && j+6<=n){
                acm = 0;
                for(int k=0;k<6;k++){
                    acm += (mat[i+k][j+k]=='#');
                }
                answ = (answ || acm>=4);
            }
            if(i+6<=n && j-5>=0){
                acm = 0;
                for(int k=0;k<6;k++){
                    acm += (mat[i+k][j-k]=='#');
                }
                answ = (answ || acm>=4);
            }
        }
    }

    if(answ){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }

    return 0;
}