#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> prox, arr;
vector<vector<int>> dp;

int solve(int i, int j){
    if(j==i+1)
        return arr[i]!=arr[j];
    if(j<=i)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j] = min(j-i,solve(i+1,j)+(arr[i]!=arr[j]));
    for(int k=prox[i];k;k=prox[k]){
        dp[i][j] = min(dp[i][j],solve(i+1,k-1)+(arr[i+1]!=arr[i])+solve(k,j));
    }
    return dp[i][j];
}

int main(){
    int t;

    cin >> t;
    while(t--){
        cin >> n;
        prox.assign(n,0), arr.assign(n,0);

        for(auto &x:arr)
            cin >> x;

        map<int,int> last;
        for(int i=n-1;i>=0;i--){
            prox[i] = last[arr[i]];
            last[arr[i]] = i;
        }

        dp.assign(n,vector<int>(n,-1));
        cout << solve(0,n-1) << "\n";
    }

    return 0;
}