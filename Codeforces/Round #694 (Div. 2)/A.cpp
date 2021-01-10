#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<ll> arr;
        ll n, mn=0, mx=0, y;
        cin >> n >> y;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;

        for(auto x:arr){
            mn+=x;
            mx += x/y + (x%y!=0);
        }

        cout << mn/y+(mn%y!=0) << " " << mx << "\n";

    }

    return 0;
}