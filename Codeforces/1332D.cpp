#include<bits/stdc++.h>
using namespace std;

int main(){
    int k, k1, j;

    cin >> k;

    for(j=31;j>=0 && (k & (1<<j))==0;j--);

    k1 = (1<<(j+1));
    if(k==0){
        cout << "1  1" << '\n';
        cout << "0\n";
    }
    else{
        cout << "3 4" << '\n';
        int answ[3][4] = {{k+k1,k,k,0},{k1,k1,k,0},{k+k1,k+k1,k+k1,k}};
        for(int i=0;i<3;i++){
            for(int j=0;j<4;j++){
                cout << answ[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}