#include<bits/stdc++.h>
#define maxn int(5e3+5)
using namespace std;

int dp[maxn][maxn];

int main(){
    int k, n;
    vector<int> arr, last;

    cin >> n >> k;
    arr.assign(n,0);
    last.assign(n+10,0);
    for(auto &x:arr)
        cin >> x;

    sort(arr.begin(),arr.end());
    for(int i=0, j=0;i<n;i++){
        while(arr[i]-arr[j]>5) j++;
        last[i+1] = j+1;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j] = max(dp[i-1][j], (i-last[i]+1) + dp[last[i]-1][j-1]);
        }
    }
    
    int answ = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++)
            answ = max(answ,dp[i][j]);
    
    cout << answ <<"\n";    
    
    return 0;
}