#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        vector<ll> arr;
        cin >> n >> k;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        sort(arr.rbegin(),arr.rend());
        int pos = 0;
        ll answ = 0;
        for(int i=0;i<k;i++){
            answ += arr[pos+1]/arr[pos];
            pos+=2;
        }
        for(int i=pos;i<n;i++){
            answ += arr[i];
        }

        ll outro  0;
        for(int i=0;i<k;i++){
            answ += arr[i]/arr[n-i-1];
        }
        cout << answ <<"\n";
    }

    return 0;   
}