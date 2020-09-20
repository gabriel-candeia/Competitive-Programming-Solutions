#include<bits/stdc++.h>
using namespace std;

int det(pair<int,int> a, pair<int,int> b, pair<int,int> c){
    return ((a.second*b.first+b.second*c.first+c.second*a.first-b.first*c.second-a.first*b.second-c.first*a.second)<0);
}

int main(){
    int n, x, y;
    pair<int,int> a = {0,0}, b = {0,0};
    vector<pair<int,int>> p;
    
    cin >> n >> a.second >> b.second;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        p.push_back({y,x});
    }
    sort(p.begin(),p.end());
    vector<int> dp(n,1);
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            if(det(p[j],p[i],a)==0 && det(p[j],p[i],b))
                dp[i] = max(dp[j]+1,dp[i]);

    int answ=0;
    for(int i=0;i<n;i++)
        answ = max(answ,dp[i]);
    cout << answ <<'\n';
    return 0;
}