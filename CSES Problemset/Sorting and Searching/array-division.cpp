#include<bits/stdc++.h>
#define ll long long
using namespace std;

int ehPossivel(vector<ll>& arr, ll x, ll k){
    ll cnt=1, sum=0;
    for(int i=0;i<arr.size();i++){
        if(sum+arr[i]>x){
            sum = arr[i];
            cnt++;
        }
        else{
            sum+=arr[i];
        }
    }

    return (cnt);
}

int main(){
    ll n, k, sum=0, mx=0;
    vector<ll> arr;

    cin >> n >> k;
    arr.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        mx = max(arr[i],mx);
        sum += arr[i];
    }

    ll l = mx, r = sum, med, answ=-1, cmp;
    while(l<=r){
        med = l + (r-l)/2;
        cmp = ehPossivel(arr,med,k); 
        if(cmp<=k){
            answ = med; 
            r = med-1;

        }
        else{
            l = med+1;
        }
    }

    cout << answ << '\n';

    return 0;
}