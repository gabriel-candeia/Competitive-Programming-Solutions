#include<bits/stdc++.h>
#define ll long long
#define maxn int(4e3)
using namespace std;

ll n, mod;
ll dp[maxn][maxn], len[maxn];

int main(){
    cin >> n >> mod;

    len[0] = 0;
    for(int i=1;i<maxn;i++)
        len[i] = len[i/10]+1;

    for(int i=n;i>=0;i--){
        for(int j=0;j<=n;j++){
            if(i==n)
                dp[i][j] = j<i;
            /*for(int x=1;i+x<=n && j+len[x]+1<=n;x++){
                dp[i][j] = (dp[i][j] + (25+(i==0))*dp[i+x][j+len[x]+1])%mod;
            }*/
            for(int pot=1,it=1;i+pot<=n && j+it+1<=n;pot=pot*10,it++){
                if(i+pot*10<maxn)
                    dp[i][j] = (dp[i][j] + ((25+(i==0))*(dp[i+pot][j+it+1]-dp[i+pot*10][j+it+1]))%mod)%mod;
                else
                    dp[i][j] = (dp[i][j] + ((25+(i==0))*dp[i+pot][j+it+1])%mod)%mod;
            }
        }
        for(int j=0;j<=n;j++){
            dp[i][j] = (dp[i][j] + dp[i+1][j])%mod;
        }
    }
    cout << ((dp[0][0]-dp[1][0])%mod+mod)%mod <<"\n";

    return 0;
}