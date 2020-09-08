#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t, n, k;
    vector<ll> a;

    cin >> t;
    while(t--){
        cin >> n >> k;
        a.assign(n,0);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        ll mn=a[0], mx=a[0];
        for(int i=0;i<n;i++){
            mn = min(mn,a[i]);
            mx = max(mx,a[i]);
        }
        
        for(int i=0;i<n;i++){
            if(k%2){
                a[i] = mx-a[i];
            }
            else{
                a[i] = a[i]-mn;
            }
            cout << a[i] << ' ';
        }cout <<'\n';
        

    }

    return 0;
}