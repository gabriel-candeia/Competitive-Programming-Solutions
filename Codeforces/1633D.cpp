#include<bits/stdc++.h>
#define maxn int(1e3+5)
#define maxm int(5e4)
using namespace std;

int n, k;
int b[maxn], c[maxn], cost[maxn];
int dp[maxn][maxm];
int solve(int i, int j){
    if(i==n)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j] = solve(i+1,j);
    if(cost[b[i]]<=j)
        dp[i][j] = max(dp[i][j],c[i] + solve(i+1,j-cost[b[i]]));
    return dp[i][j];
}

int teto(int a, int b){
    return a/b + ((a%b)!=0);
}

int main(){
    int mx = 0;
    for(int i=0;i<=1000;i++) cost[i] = 1000;
    cost[1] = 0;
    for(int i=1;i<=1000;i++){
        for(int j=i;j>0;j--){
            cost[i + i/j] = min(cost[i + i/j],cost[i]+1);
        }
        mx = max(mx,cost[i]);
    }
    //cout << mx <<"\n";

    int t;

    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=0;i<n;i++)
            cin >> b[i];
        for(int i=0;i<n;i++)
            cin >> c[i];
        
        int answ = 0;
        if(k>=maxm){
            for(int i=0;i<n;i++)
                answ += c[i];
        }
        else{
            for(int i=0;i<n;i++){
                for(int j=0;j<maxm;j++){
                    dp[i][j] = -1;
                }
            }
            answ = solve(0,k);
        }
        cout << answ <<"\n";
    }

    return 0;
}