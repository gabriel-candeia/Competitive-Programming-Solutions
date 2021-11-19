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

        arr.assign(n+2,0);
        for(int i=1;i<=n;i++) cin >> arr[i];

        ll answ =  arr[0];
        for(int i=1;i<=n;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
                answ+=arr[i]-max(arr[i-1],arr[i+1]), arr[i] = max(arr[i-1],arr[i+1]);
        }
        
        for(int i=1;i<=n+1;i++){
            answ += abs(arr[i]-arr[i-1]);
        }

       cout << answ <<'\n';
    }

    return 0;
}