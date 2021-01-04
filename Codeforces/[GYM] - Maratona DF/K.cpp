#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

int dp[maxn];

int main(){
    int n, m, a, b, x1, y1;

    cin >> n >> m >> a >> b;
    for(int i=0;i<m;i++)
        cin >> x1 >> y1;

    int x = m-(n-1);
    dp[0] = 0;
    for(int i=0;i<x;i++){
        if(i+a<=x)
            dp[i+a] = max(dp[i+a],1-dp[i]);
        if(i+b<=x)
            dp[i+b] = max(dp[i+b],1-dp[i]);
    }

    if(dp[x])
        cout << "Ana\n";
    else
        cout << "Beto\n";

    return 0;
}