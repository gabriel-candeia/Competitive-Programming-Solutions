#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, x;
    vector<ll> arr;

    cin >> n >> x;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    map<ll,pair<ll,ll>> freq;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(freq.find(x-arr[i]-arr[j])!=freq.end()){
                ll a, b;
                tie(a, b) = freq[x-arr[i]-arr[j]];
                cout << a+1 << " " << b+1 << " " << i+1 << " " << j+1 <<"\n";
                return 0;
            }
        }
        for(int j=i-1;j>=0;j--)
            freq[arr[i]+arr[j]] = {i,j};
    }

    cout << "IMPOSSIBLE" <<"\n";

    return 0;
}