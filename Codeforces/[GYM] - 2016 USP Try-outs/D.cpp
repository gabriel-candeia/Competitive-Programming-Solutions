#include<bits/stdc++.h>
#define maxn 1e5+5
#define ll long long
using namespace std;

ll isok(vector<ll> &arr, ll x){
    ll answ = 0;
    for(int j=arr.size()-1, i=0;j>=0;j--){
        if(i>=j) i = j-1;
        for(;i<j && arr[j]+arr[i]<=x;i++);
        answ += max(i,0);        
    }
    return (answ);
}

int main(){
    ll n, k;
    vector<ll> arr;

    cin >> n >> k;

    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    sort(arr.begin(),arr.end());

    ll l = 0, r = 1e10, med = 0, answ = -1;
    while(l<=r){
        med = l + (r-l)/2;
        if(isok(arr,med)>=k){
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