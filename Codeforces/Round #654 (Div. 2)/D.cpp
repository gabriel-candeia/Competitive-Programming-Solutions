#include<bits/stdc++.h>
#define N 400
using namespace std;

int comp(vector<int>& a){
    int mx = 0, mn = 0;
    for(int i=0;i<a.size();i++){
        if(a[mx]<a[i]){
            mx = i;
        }
        if(a[mn]>a[i]){
            mn = i;
        }
    }
    return (a[mx]-a[mn])*((a[mx]-a[mn]));
}

int main(){
    int t, mat[N][N], n, k;

    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<int> col(n,0), row(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = 0;
            }
        }
        int i=0, j=0;
        while(k--){
            if(mat[i][j]==1){
                i++;
                i = (i%n);
            }
            mat[i][j] = 1;
            col[j]++;
            row[i]++;
            i++;
            i = (i%n);
            j++;
            j = (j%n);
        }
        cout << comp(col)+comp(row) << '\n';
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << mat[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}