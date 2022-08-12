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
    sort(arr.rbegin(),arr.rend());

    ll acm = 0;
    for(auto x:arr)
        acm += x;

    
    
    if(acm%2==0 && acm-arr[0]>=arr[0])
        cout << "YES\n";
    else
        cout << "NO\n";


    return 0;   
}