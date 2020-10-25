#include<bits/stdc++.h>
#define maxn 30
#define ll long long
using namespace std;

ll dp[maxn][maxn], digits[maxn], tam, m, n, sum[maxn];
ll solve(int i, int lim){
    if(dp[i][lim]!=-1)
        return dp[i][lim];
    if(i==0)
        return dp[i][lim] = (m<=lim);
    dp[i][lim] = 0;
    if(lim==10)
        return dp[i][lim] = 10*solve(i-1,10) + (pow(10,i)-solve(i-1,10));
    if(lim!=10)
        return dp[i][lim] = solve(i-1,digits[i-1]) + (lim)*solve(i-1,10) + (m<lim)*(pow(10,i)-solve(i-1,10))+(lim==m)*(sum[i-1]+1-solve(i-1,digits[i-1]));
}


/*
ll teste(int lim, int x){
    int cnt=0;
    for(int i=0;i<=lim;i++){
        for(int j=i;j;j/=10){
            if(j%10==x){
                cnt++;
                break;
            }
        }
    }
    return cnt;
}*/

int main(){
    cin >> n >> m;
    cout << teste(n,m) << "\n";
    do{
        digits[tam++] = n%10;
    }while(n/=10);
    memset(dp,-1,sizeof(dp));
    memset(dp1,-1,sizeof(dp1));
    sum[0] = digits[0];
    for(int i=1;i<tam;i++)
        sum[i]+=sum[i-1]+digits[i]*pow(10,i);
    
    cout << solve(tam-1,digits[tam-1]) << "\n";
    return 0;
}   