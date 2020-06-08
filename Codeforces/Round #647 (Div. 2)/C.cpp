#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t, ptr;
    ll n;
    vector<ll> arr(100,0);
    ll answ=0;

    arr[0] = 1;
    for(int i=1;i<=62;i++){
        arr[i] = 2ll*arr[i-1]+1;
    }

    cin >> t;
    while(t--){
        cin >> n;
        answ=0;
        ptr = 0;
        while(n!=0){
            if(n%2){
                answ+=arr[ptr];
            }
            n/=2;
            ptr++;
        }
        cout << answ << '\n';
    }

    return 0;
}