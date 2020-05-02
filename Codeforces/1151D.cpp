#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    ll sum=0, a, b;
    vector<ll> arr;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        sum += 1ll*n*b-a;
        arr.push_back(a-b);
    }
    sort(arr.rbegin(),arr.rend());

    for(int i=0;i<n;i++){
        sum += (i+1)*arr[i];
    }

    cout << sum << '\n';

    return 0;
}