#include<bits/stdc++.h>
#define maxn 105
using namespace std;

double dp[maxn][maxn][maxn];
int visited[maxn][maxn][maxn];
double solve(int a, int b, int c){
    if(a==100 || b==100 || c==100)
        return 0;
    if(visited[a][b][c]!=-1)
        return dp[a][b][c];
    visited[a][b][c] = 1;
    return dp[a][b][c] = 1 + (a*solve(a+1,b,c)+b*solve(a,b+1,c)+c*solve(a,b,c+1))*1.0/(a+b+c);
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    memset(visited,-1,sizeof(visited));
    cout << fixed << setprecision(8) << solve(a,b,c) <<'\n';
    return 0;
}