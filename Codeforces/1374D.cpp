#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t, n, k, a;
    cin >> t;

    while(t--){
        cin >> n >> k;
        map<ll,ll> mp;
        ll mx=0,mval=0, temp;
        for(int i=0;i<n;i++){
            cin >> a;
            if(a%k){
                mp[k-a%k]++;
                temp = mp[k-a%k];
                if(temp>mx || (temp==mx && k-a%k>=mval)){
                    mval = k-a%k;
                    mx = temp;
                }
            }
        }
        if(mx==0){
            cout << 0 << '\n';
        }
        else{
            cout << 1ll*(mx-1)*k+mval+1 << '\n';
        }
    }

    return 0;
}