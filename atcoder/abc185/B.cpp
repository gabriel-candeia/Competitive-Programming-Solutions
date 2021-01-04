#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, m, t, mx;
    vector<pair<ll,ll>> arr;

    cin >> n >> m >> t;
    mx = n;
    arr.assign(m+1,{0,0});
    for(int i=1;i<=m;i++)
        cin >> arr[i].first >> arr[i].second;


    bool poss = true;
    arr.push_back({t,-1});
    for(int i=1;i<=m+1;i++){
        n-= arr[i].first-arr[i-1].second;
        if(n<=0) poss = false;
        n+= max(arr[i].second-arr[i].first,0ll);
        n = min(n,mx);
    }

    if(poss==false)
        cout << "No\n";
    else
        cout << "Yes\n";
}