#include<bits/stdc++.h>
#define ll long long
#define maxn 25
using namespace std;

vector<int> digits;
int dp[maxn][maxn][maxn], answ=25;
void solve(int pos, int removed, int mod){
    if(pos==digits.size()){
        if(mod==0)
            answ = min(answ,removed);
        return;
    }
    if(dp[pos][removed][mod]==-1){
        dp[pos][removed][mod] = 1;
        solve(pos+1,removed,(mod*10+digits[pos])%25);
        solve(pos+1,removed+1,mod);    
    }
}

int main(){
    int t;

    cin >> t;
    while(t--){
        ll n;
        cin >> n;

        answ = 25;
        digits.clear();
        while(n){
            digits.push_back(n%10);
            n = n/10;
        }
        reverse(digits.begin(),digits.end());

        memset(dp,-1,sizeof(dp));
        solve(0,0,0);
        cout << answ <<"\n";
    }

    return 0;
}