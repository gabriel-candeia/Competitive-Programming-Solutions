#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, k;
    vector<pair<ll,ll>> arr;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        arr.push_back({a,b});
    }

    sort(arr.rbegin(),arr.rend());
    ll answ = 0;
    for(int i=0;i<n;i++){
        answ += arr[i].first*min(k,arr[i].second);
        k -= min(k,arr[i].second);
    }

    cout << answ <<"\n";

    return 0;
}