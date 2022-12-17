#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> price, page, copies;

int solve(){
    vector<int> dp(vector<int>(m+1,0));

    for(int i=0;i<n;i++){
        for(int qtd=1;copies[i]!=0;qtd = min(2*qtd,copies[i])){
            copies[i] -= qtd;
            int wt = price[i]*qtd, value = page[i]*qtd;
            for(int j=m;j>=wt;j--){
                dp[j] = max(dp[j],dp[j-wt]+value);
            }
        }
    }

    return dp[m];
}

int main(){
    cin >> n >> m;
    price.assign(n,0);
    page.assign(n,0);
    copies.assign(n,0);
    for(auto &x:price)
        cin >> x;
    for(auto &x:page)
        cin >> x;
    for(auto &x:copies)
        cin >> x;


    cout << solve() <<"\n";

    return 0;
}