#include<bits/stdc++.h>
#define ld long double
#define maxn 3005
using namespace std;

ld dp[maxn], p[maxn], n;

ld solve(){
    dp[0] = 1;
    for(int i=0;i<n;i++)
        for(int j=n;j>=0;j--){
            dp[j] *= (1-p[i]);
            if(j) dp[j] += p[i]*dp[j-1];
        }

    ld sum=0;
    for(int j=n;j>n/2;j--)
        sum+=dp[j];

    return sum;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> p[i];
    
    cout << setprecision(10) << solve() <<'\n';
    return 0;
}