#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    vector<ll> arr;

    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    ll mn = arr[0], mx = arr[0];
    for(int i=0;i<n;i++){
        mn = min(mn,arr[i]);
        mx = max(mx,arr[i]);
    }

    cout << (mx-mn)*n <<"\n";

    return 0;
}