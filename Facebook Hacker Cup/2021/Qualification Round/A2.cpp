#include<bits/stdc++.h>
#define maxn 26
#define ll long long
using namespace std;

const ll inf = 1e9;
ll dp[maxn+1][maxn][maxn];

int main(){
    int t, caso=0;

    cin >> t;
    while(t--){
        string s;
        int k;

        cin >> s;   

        for(int k=0;k<=maxn;k++)
            for(int i=0;i<maxn;i++)
                for(int j=0;j<maxn;j++)
                    dp[k][i][j] = (i==j) ? 0 : inf;
                

        cin >> k;
        for(int i=0;i<k;i++){
            char a, b;
            cin >> a >> b;
            dp[0][a-'A'][b-'A'] = 1;
        }

        for(int k=1;k<=maxn;k++)
            for(int i=0;i<maxn;i++)
                for(int j=0;j<maxn;j++)
                    dp[k][i][j] = min({dp[k][i][j],dp[k-1][i][k-1]+dp[k-1][k-1][j],dp[k-1][i][j]});
        
        ll answ = inf;
        for(int k=0;k<maxn;k++){
            ll temp = 0;
            for(auto c:s){
                temp += dp[maxn][c-'A'][k];
            }
            //cout << (char)(k+'A') << " " << temp <<"\n";
            answ = min(answ,temp);
        }
        if(answ==inf)
            answ = -1;
        cout << "Case #" << ++caso << ": " << answ <<"\n";
    }

    return 0;
}