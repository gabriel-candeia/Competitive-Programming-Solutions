#include<bits/stdc++.h>
#define maxn 5005
#define ll long long
using namespace std;

const ll inf = 1e18;
ll arr[maxn], answ, n, dp[2][maxn][maxn];
ll solve(int turno, int i, int j){
    if(i>j)
        return dp[turno][i][j] = 0;
    if(dp[turno][i][j]!=inf)
        return dp[turno][i][j];
    if(turno)
        return (dp[turno][i][j] = max(solve(!turno,i+1,j)+arr[i],solve(!turno,i,j-1)+arr[j]));
    return (dp[turno][i][j] = min(solve(!turno,i+1,j)-arr[i],solve(!turno,i,j-1)-arr[j]));
}

int main(){
    cin >> n;
    answ = 0;

    for(int i=0;i<2;i++)
        for(int j=0;j<maxn;j++)
            for(int k=0;k<maxn;k++)
                dp[i][j][k] = inf;

    for(int i=0;i<n;i++){
        cin >> arr[i];
        answ+=arr[i];
    }
    answ+=solve(1,0,n-1);
    cout << answ/2 << '\n';
    return 0;
}