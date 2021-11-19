#include<bits/stdc++.h>
#define maxn int(1e2+1);
#define maxm int(1e5+1)
using namespace std;

vector<int> items;
int dp[maxm], n;   

int main(){
    cin >> n;
    items.assign(n,0);
    for(auto &x:items)
        cin >> x;

    int total = 0;
    for(auto x:items) total+=x;

    dp[0] = 1;
    for(int i=0;i<n;i++)
        for(int j=maxm-1;j>=items[i];j--)
            dp[j] |= dp[j-items[i]];
    
    int answ = maxm;
    for(int j=0;j<maxm;j++)
        if(dp[j])
            answ = min(answ,max(j,total-j));

    cout << answ <<'\n';
    return 0;
}