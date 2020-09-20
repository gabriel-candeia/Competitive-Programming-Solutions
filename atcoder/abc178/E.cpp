#include<bits/stdc++.h>
#define ll long long
using namespace std;
    
int main(){
    ll n, x, y;
    vector<pair<ll,ll>> a;
    vector<ll> arrx, arry;
    
    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> x >> y;
        a.push_back({x,y});
        arrx.push_back(x+y);
        arry.push_back(y-x);
    }
    sort(arrx.begin(),arrx.end());
    sort(arry.begin(),arry.end());
    ll mx = 0;

    for(int i=0;i<n;i++){
        mx = max({mx,abs(arrx[i]-arrx[0]),abs(arrx[i]-arrx[n-1])});
        mx = max({mx,abs(arry[i]-arry[0]),abs(arry[i]-arry[n-1])});
    }

    cout << mx <<'\n';
    
    return 0;
}