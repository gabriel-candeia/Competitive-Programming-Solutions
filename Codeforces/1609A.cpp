#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n,0);
        for(auto &x:arr)
            cin >> x;
        
        ll prod = 1;
        for(auto &x:arr){
            while(x%2==0){
                prod = prod*2;
                x/=2;
            }
        }
        sort(arr.begin(),arr.end());
        arr[n-1]*=prod;
        ll answ = 0;
        for(auto &x:arr)
            answ +=x;
        cout <<answ <<"\n";

    }


    return 0;
}