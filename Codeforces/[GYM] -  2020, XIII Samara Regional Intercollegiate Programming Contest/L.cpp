#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;

    cin >> n;
    vector<ll> arr;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;
    
    sort(arr.rbegin(),arr.rend());

    ll answ = 0, acm = 0;
    for(int i=0;i<n;i++){
        acm += arr[i]-i-1;
        answ = max(answ,acm);
    }

    cout << answ << "\n";


    return 0;
}