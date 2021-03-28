#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        bool poss = true;
        ll  n, sum=0;
        cin >> n;
        vector<ll> arr;
        arr.assign(n,0);
        for(ll i=0;i<n;i++){
            cin >> arr[i];   
            sum += arr[i]-i;
            poss = poss&&(sum>=0);
        }
        if(poss)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}