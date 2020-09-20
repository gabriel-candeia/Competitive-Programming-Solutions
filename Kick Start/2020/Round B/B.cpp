#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t, caso = 0;

    cin >> t;
    while(t--){
        ll n, d;
        cin >> n >> d;
        vector<ll> arr(n,0);

        for(auto &x:arr)
            cin >> x;

        for(int i=n-1;i>=0;i--)
            d = (d-d%arr[i]);

        cout << "Case #" << ++caso << ": " << d <<'\n';
    }
    return 0;
}