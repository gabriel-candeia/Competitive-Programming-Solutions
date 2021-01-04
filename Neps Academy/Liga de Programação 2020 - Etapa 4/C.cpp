#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, k;
    vector<ll> arr;

    cin >> n >> k;
    arr.assign(n,0);
    for(auto &x:arr) cin >> x;
    sort(arr.rbegin(),arr.rend());

    ll answ = 0, total = n;
    for(int i=0;i<n && total;i++){
        answ += arr[i]*min(total,k);
        total-=min(total,k);
    }

    cout << answ <<"\n";
    
    return 0;
}