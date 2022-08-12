#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    vector<ll> arr, aux;

    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    aux.push_back(arr[0]);
    for(int i=1;i<n;i++){
        aux.push_back(arr[i]-aux.back());
    }

    ll mn=0, mx=1e8;

    for(int i=0;i<n;i+=2){
        mx = min(mx,aux[i]);
    }

    for(int i=1;i<n;i+=2){
        mn = max(mn,-aux[i]);
    }
    //cout << mx << " " << mn <<"\n";
    cout << max(0ll,mx-mn+1) <<"\n";

    return 0;
}
