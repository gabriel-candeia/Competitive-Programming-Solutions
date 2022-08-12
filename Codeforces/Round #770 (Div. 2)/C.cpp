#include<bits/stdc++.h>
#define maxn int(505)
using namespace std;

int mat[maxn][maxn];
int main(){
    int t;

    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        bool answ = ((n%2==0) || (k==1));

        int cnt = 0;
        for(int j=0;j<k;j++){
            for(int i=0;i<n;i++){
                mat[i][j] = ++cnt;
            }
        }

        if(answ){
            cout << "YES\n";
            for(int i=0;i<n;i++){
                for(int j=0;j<k;j++){
                    cout << mat[i][j] << " ";
                }
                cout <<"\n";
            }
        }
        else{
            cout << "NO\n";
        }
    }


    return 0;
}