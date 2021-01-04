#include<bits/stdc++.h>
#define maxn 10
#define ll long long
using namespace std;

ll mat[maxn][maxn], n,k;
ll solve(ll u, ll msk, ll sum){
    if(msk == 0 && u==0)
        return (sum)==k;
    ll acm = 0;
    for(int i=0;i<n;i++)
        if(msk&(1<<i))
            acm += solve(i,msk^(1<<i),sum+mat[u][i]);
    return acm;
}

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> mat[i][j];

    cout << solve(0,((1<<n)-1),0) <<'\n';

    return 0;
}