#include<bits/stdc++.h>
#define maxn int(100+5)
using namespace std;

int cost[maxn][maxn], dp[maxn][maxn][maxn], visited[maxn][maxn][maxn], k, n;
string s;
int solve(int i, char x, int k){
    if(k<0)
        return -int(1e7);
    if(i==n-1)
        return 0;
    if(visited[i][x-'a'][k]!=-1)
        return dp[i][x-'a'][k];

    visited[i][x-'a'][k] = 1;
    dp[i][x-'a'][k] = -int(1e7);

    for(char j='a';j<='z';j++)
        dp[i][x-'a'][k] = max(dp[i][x-'a'][k],cost[x-'a'][j-'a']+solve(i+1,j,k-(s[i+1]!=j)));

    return dp[i][x-'a'][k];
}


int main(){
    cin >> s >> k;
    n = s.size();

    int m;
    cin >> m;
    while(m--){
        char a, b;
        int w;
        cin >> a >> b >> w;
        cost[a-'a'][b-'a'] = w;
    }

    int answ = -int(1e7);
    memset(dp,-1,sizeof(dp));
    memset(visited,-1,sizeof(visited));

    for(char i='a';i<='z';i++){
        answ = max(answ,solve(0,i,k-(i!=s[0])));
    }

    cout << answ <<'\n';
    return 0;
}