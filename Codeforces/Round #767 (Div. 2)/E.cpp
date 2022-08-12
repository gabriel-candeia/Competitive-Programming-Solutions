#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        vector<vector<int>> original, mat;

        cin >> n;
        original.assign(n,vector<int>(n,0));
        mat.assign(n,vector<int>(n,0));
        for(auto &x:mat)
            for(auto &y:x)
                cin >> y;
        
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n;j++){
                int aux = mat[i][j];
                if(i-1>=0) aux = aux^original[i-1][j];
                if(j-1>=0) aux = aux^original[i][j-1];
                if(j+1<n) aux = aux^original[i][j+1];
                original[i+1][j] = aux;
            }
        }

        int answ = 0;
        for(auto &x:original)
            for(auto &y:x)
                answ = answ^y;

        cout << answ <<"\n";
    }

    return 0;
}