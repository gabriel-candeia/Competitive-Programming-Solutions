#include<bits/stdc++.h>
#define ld long double
#define maxn int(201)
using namespace std;

int n, m, k;
ld dp[maxn][maxn][2*maxn];
vector<int> p, a;

ld solve(int i, int j, int c){
    if(i==n) return (j==0 && c>=200);
    else if(dp[i][j][c]>-1) return dp[i][j][c];
    dp[i][j][c] = ((p[i]/100.0)*solve(i+1,max(j-1,0),min(c+a[i],400)))+(1-p[i]/100.0)*solve(i+1,j,c);
    return dp[i][j][c]; 
}

int main(){
    memset(dp,-1,sizeof(dp));
    
    cin >> n >> m >> k;
    p.assign(n,0), a.assign(n,0);
    for(auto &x:p) cin >> x;
    for(auto &x:a) cin >> x;
    cout << fixed << setprecision(10) << solve(0,m,200+k) << '\n';  
    return 0;
}