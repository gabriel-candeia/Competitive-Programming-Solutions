#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, k;
vector<ll> arr;

bool isok(ll med){
    ll acm = 0;
    for(int i=n/2;i<n;i++){
        acm += max(0ll,med-arr[i]);
    }
    return acm<=k;
}

int main(){
    cin >> n >> k;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    sort(arr.begin(),arr.end());

    ll l = arr[n/2]+1, r = 1e14, med, answ=arr[n/2];
    while(l<=r){
        med = l + (r-l)/2;
        if(isok(med)){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }

    cout << answ <<"\n";

    return 0;
}