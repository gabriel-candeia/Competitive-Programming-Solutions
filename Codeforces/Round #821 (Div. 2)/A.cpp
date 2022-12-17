#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        for(auto &x:arr)
            cin >> x;

        ll answ = 0;
        for(int i=0;i<k;i++){
            ll total = 0;
            for(int j=i;j<n;j+=k){
                total = max(total,arr[j]);
            }
            answ += total;
        }

        cout << answ <<"\n";
    }

    return 0;
}