#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        vector<ll> arr;
        cin >> n;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        ll a = arr[0], b = arr[1], d;
        for(int i=0;i<n;i+=2){
            a = __gcd(a,arr[i]);
        }
        for(int i=1;i<n;i+=2){
            if(arr[i]%a==0){
                a = 1;
                break;
            }
        }
        for(int i=1;i<n;i+=2){
            b = __gcd(b,arr[i]);
        }
        for(int i=0;i<n;i+=2){
            if(arr[i]%b==0){
                b = 1;
                break;
            }
        }
        if(a==1 && b==1){
            cout << "0" <<"\n";
        }
        else{
            cout << max(a, b) <<"\n";
        }
    }

    return 0;
}