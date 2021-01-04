#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll acm = 0, n,  m;

    cin >> m >> n;
    vector<ll> arr(m,0);
    for(auto &x:arr)
        cin >> x;

    for(int i=0;i<n;i++)
        acm+=arr[i];
    
    cout << fixed << setprecision(8) << acm/(1.0*n) << "\n";
    for(int i=n;i<m;i++){
        acm += arr[i]-arr[i-n];
        cout << fixed << setprecision(8) << acm/(1.0*n) << "\n";
    }

    return 0;
}