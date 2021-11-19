#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    vector<ll> arr;

    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;
    ll answ = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            answ += arr[i]*arr[j];
        }
    }
    cout << answ <<"\n";
    return 0;   
}