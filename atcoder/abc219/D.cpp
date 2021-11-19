#include<bits/stdc++.h>
#define maxn int(305)
using namespace std;

int dp[2][maxn][maxn];

int main(){
    int n, x, y;
    vector<array<int,2>> arr;

    cin >> n >> x >> y;
    arr.assign(n,array<int,2>());
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<2;i++)
        for(int j=0;j<maxn;j++)
            for(int k=0;k<maxn;k++)
                dp[i][j][k] = n+1;
    dp[0][0][0] = 0;
    for(int i=0;i<n;i++){
        int curr = i%2, nxt = 1-curr;
        for(int j=0;j<maxn;j++){
            for(int k=0;k<maxn;k++){
                dp[nxt][j][k] = min(dp[nxt][j][k],dp[curr][j][k]);
                dp[nxt][min(300,j+arr[i][0])][min(300,k+arr[i][1])] = min(dp[nxt][min(300,j+arr[i][0])][min(300,k+arr[i][1])],dp[curr][j][k]+1);
            }
        }
    }

    int answ = n+1;
    for(int i=x;i<maxn;i++)
        for(int j=y;j<maxn;j++)
            answ = min(answ,dp[n%2][i][j]);
    if(answ==n+1)
        answ = -1;
    cout << answ << "\n";

    return 0;
}