#include<bits/stdc++.h>
#define N 1005
#define M 100005
using namespace std;

int n, x[N], dp[N][M];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<M;j++){
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            dp[i+1][j+x[i]] = max(dp[i+1][j+x[i]],dp[i][j]);
        }
    }

    int answ=0;
    for(int i=1;i<M;i++){
        answ+=dp[n][i];
    }
    cout << answ << '\n';
    for(int i=1;i<M;i++){
        if(dp[n][i]){
            cout << i << ' ';
        }
    }cout << '\n';

    return 0;
}