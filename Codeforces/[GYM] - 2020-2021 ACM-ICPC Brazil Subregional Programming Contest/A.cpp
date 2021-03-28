#include<bits/stdc++.h>
#define ld double
#define maxn int(1e6+5)
using namespace std;

int n, a, b;
ld dp[maxn];

ld solve(){
    dp[0] = 0;
    for(int i=1;i<maxn;i++){
        dp[i] = 1.0+(dp[max(i-max(a,1),0)]-dp[max(i-(b+1),0)])/(b-a+1);
        if(a==0) dp[i] = (b-a+1)*dp[i]/(b-a);
        dp[i]+=dp[i-1];
    }
    return dp[n]-dp[n-1];
}

int main(){
    cin >> n >> a >> b;
    cout << fixed << setprecision(10) <<  solve() << "\n";
    return 0;
}