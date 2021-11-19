#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll binpow(ll x, ll y){
    ll answ = 1;
    for(;y;y>>=1){
        if(y&1)
            answ = answ*x;
        x = (x*x);
    }
    return answ;
}

int main(){
    int t;

    cin >> t;
    while(t--){
        ll n, k;
        vector<int> arr;

        cin >> n >> k;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        k++;
        ll answ = 0;
        
        for(int i=0;i<arr.size()-1;i++){
            ll diff = (binpow(10,arr[i+1])-binpow(10,arr[i]))/binpow(10,arr[i]);
            if(diff<=k){
                answ += diff*binpow(10,arr[i]);
                k-=diff;
            }
            else{
                answ += k*binpow(10,arr[i]);
                k = 0;
                break;
            }
        }

        cout << answ+k*binpow(10,arr[n-1]) <<"\n";
    }
    return 0;
}