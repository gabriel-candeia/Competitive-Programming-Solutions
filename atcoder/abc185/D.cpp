#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, m, d;
    vector<ll> arr;

    cin >> n >> m;
    arr.assign(m+2,0);
    arr[0] = 0; arr[m+1] = n+1;
    for(int i=1;i<=m;i++)
        cin >> arr[i];
    sort(arr.begin(),arr.end());

    d = 1e17;
    for(int i=1;i<=m+1;i++)
        if(arr[i]-arr[i-1]-1>=1)
            d = min(arr[i]-arr[i-1]-1,d);

    ll answ = 0;
    for(int i=1;i<=m+1;i++){
        answ += (arr[i]-arr[i-1]-1)/d + ((arr[i]-arr[i-1]-1)%d!=0);
    }

    cout << answ <<"\n";
    return 0;
}