#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, n;
    set<pair<int,int>> s;
    vector<pair<int,int>> p; 
    vector<int> dp; 

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a >> b;
        p.push_back({a,b});
    }
    sort(p.begin(),p.end());

    dp.assign(n+1,0);s.insert({-1,0});
    for(int i=1;i<=n;i++){
        a = p[i-1].first; b = p[i-1].second;
        auto it = s.upper_bound({max(a-b,0),0}); it--;
        dp[i] = dp[(*it).second] + (i-(*it).second-1);
        s.insert({a,i});
    }

    int answ = n+1;
    for(int i=1;i<=n;i++){
        answ = min(answ,dp[i]+n-i);
    }
    cout << answ <<'\n';

    return 0;
}