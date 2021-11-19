#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        ll m;
        vector<ll> arr(3,0);

        for(auto &x:arr)
            cin >> x;
        cin >> m;
        sort(arr.begin(),arr.end());
        ll mx = arr[0]-1+arr[1]-1+arr[2]-1, mn = arr[2]-1-arr[0]-arr[1];

        if(m<=mx && m>=mn)
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";

    }

    return 0;
}