#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> arr, dp;

int main(){
    int n, cnt;
    cin >> n >> cnt;
    
    arr.assign(2,vector<int>(n,0));
    dp.assign(2,vector<int>(n,0));

    for(int k=0;k<2;k++){
        for(int i=0;i<n;i++){
            cin >> arr[k][i];
        }
    }
    
    dp[0][0] = dp[1][0] = 1;
    
    for(int i=1;i<n;i++){
        for(int k=0;k<2;k++){
            for(int lk=0;lk<2;lk++){
                dp[k][i] = dp[k][i] || (dp[lk][i-1] && abs(arr[k][i]-arr[lk][i-1])<=cnt);
            }   
        }
    }

    cout << ((dp[0][n-1] || dp[1][n-1]) ? "Yes" : "No") <<"\n";

    return 0;
}