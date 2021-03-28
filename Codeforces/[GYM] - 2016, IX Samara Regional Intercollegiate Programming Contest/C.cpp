#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    vector<ll> arr;

    cin >> n; arr.assign(n,0);

    for(auto &x:arr)
        cin >> x;

    sort(arr.begin(),arr.end());

    ll answ = arr[n-1]-arr[0]+1;

    if(answ < arr[0]+arr[1]){
        cout << "YES\n";
        cout << answ <<'\n';
    }
    else{
        cout << "NO\n";
    }
    return 0;
}