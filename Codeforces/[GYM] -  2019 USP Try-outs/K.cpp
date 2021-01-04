#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll res, n;
    vector<ll> arr;

    cin >> n;
    arr.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    ll sum = 0, answ = 1;
    for(int i=0;i<n && arr[i]<=answ;i++)
        answ+=arr[i];

    cout << answ <<'\n';

    return 0;
}