#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, a, b;
    vector<ll> arr;
    ll sum = 0;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        sum-=a;
        arr.push_back(2*a+b);
    }

    sort(arr.rbegin(),arr.rend());
    int answ=0;
    for(answ=0;answ<n && sum<=0;sum+=arr[answ++]);

    cout << answ<<'\n';

    return 0;
}