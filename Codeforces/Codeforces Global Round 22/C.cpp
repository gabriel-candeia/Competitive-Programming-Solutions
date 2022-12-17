#include<bits/stdc++.h>
#define maxn 101
using namespace std;

int dp[2][maxn][maxn][2];
int solve(int player, int even, int odd, int parity){
    if(even+odd == 0)
        return 1-parity;
    if(dp[player][even][odd][parity]!=-1)
        return dp[player][even][odd][parity];

    auto &val = dp[player][even][odd][parity];
    if(player){
        val = 1;
        if(even)
            val = min(val,solve(1-player,even-1,odd,parity));
        if(odd)
            val = min(val,solve(1-player,even,odd-1,parity));
    }
    else{
        val = 0;
        if(even)
            val = max(val,solve(1-player,even-1,odd,parity));
        if(odd)
            val = max(val,solve(1-player,even,odd-1,1-parity));
    }
    return val;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int t;
    cin >> t;
    while(t--){
        int n;
        int even = 0, odd = 0;
        cin >> n;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            even += (abs(x)%2 == 0);
            odd += (abs(x)%2 == 1);
        }

        bool answ = solve(0,even,odd,0);

        cout << ((answ) ? "Alice" : "Bob") <<"\n";
        
    }

    return 0;
}