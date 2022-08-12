#include<bits/stdc++.h>
#define ll long long
#define maxn 20
using namespace std;

vector<int> digits;
ll dp[maxn][11][2][2];

ll solve(int i, int last, int lock, int zero){
    if(i==digits.size()){
        return 1;
    }
    if(dp[i][last][lock][zero]!=-1){
        return dp[i][last][lock][zero];
    }
    dp[i][last][lock][zero] = 0;
    for(int nxt=0;nxt<10;nxt++){
        if((nxt==last && (nxt!=0 || zero==false)) || (nxt>digits[i] && lock)) continue;
        if(lock==false)
            dp[i][last][lock][zero] = dp[i][last][lock][zero] + solve(i+1,nxt,lock,zero&&(nxt==0));
        else
            dp[i][last][lock][zero] = dp[i][last][lock][zero] + solve(i+1,nxt,nxt==digits[i],zero&&(nxt==0));
    }
    return dp[i][last][lock][zero];
}

ll wrapper(ll n){
    digits.clear();
    while(n){
        digits.push_back(n%10);
        n/=10;
    }
    reverse(digits.begin(),digits.end());
    memset(dp,-1,sizeof(dp));
    return solve(0,11,1,1);
}

int main(){
    ll a, b;

    cin >> a >> b;

    if(a-1>=0)
        cout << (wrapper(b) - wrapper(a-1)) <<"\n";
    else
        cout << wrapper(b) <<"\n";

    return 0;   
}
