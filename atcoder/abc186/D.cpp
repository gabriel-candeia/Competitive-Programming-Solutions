#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    vector<ll> arr;

    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;
    
    sort(arr.begin(),arr.end());
    ll answ = 0;
    for(int i=0;i<n;i++){
        answ  += i*arr[i] - (n-i-1)*arr[i];
    }
    cout << answ <<'\n';

    return 0;
}