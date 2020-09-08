#include<bits/stdc++.h>
#define maxn 2005
using namespace std;

int dp[maxn][maxn], st[maxn][maxn];

int main(){
    int t, caso=0;
    cin >> t;
    while(t--){
        memset(dp,0,sizeof dp);
        int n, k, p;

        cin >> n >> k >> p;
        for(int i=0;i<n;i++){
            st[i][0] = 0;
            for(int j=1;j<=k;j++){
                cin >> st[i][j];
                st[i][j] += st[i][j-1];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<=p;j++){
                for(int l=0;l<=k && j+l<=p;l++){
                    dp[i+1][j+l] = max(dp[i+1][j+l],dp[i][j]+st[i][l]);
                }
            }
        }

        cout << "Case #"<<++caso<<": "<<dp[n][p] <<'\n';

    }


    return 0;
}