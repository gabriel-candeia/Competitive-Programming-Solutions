#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll t, n;
    

    cin >> t;
    while(t--){
        cin >> n;
        
        vector<ll> arr;
        int h=2;
        arr.push_back(2);
        while(arr.back()<n){
            arr.push_back(arr.back()+3*h-1);
            h++;
        }

        ll cnt=0;
        for(int i=arr.size()-1;i>=0;i--){
            while(arr[i]<=n){
                n-=arr[i];
                cnt++;
            }
        }

        cout << cnt << '\n';
    }
    return 0;
}