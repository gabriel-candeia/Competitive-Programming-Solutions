#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        vector<ll> arr;

        cin >> n >> k; arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        
        sort(arr.rbegin(),arr.rend());
        ll answ = 0;
        for(int i=k;i<n;i++)
            answ += arr[i];
        cout << answ + max(arr[0]-answ,0ll) << "\n";
    }

    return 0;
}