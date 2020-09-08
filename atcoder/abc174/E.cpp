#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> arr;
ll n, k;

int isOk(ll x){
    bool odd = false;
    ll cnt=0;
    for(int i=0;i<n;i++){
        cnt+=(arr[i]/x + (arr[i]%x!=0)-1);
    }
    return (cnt<=k);
}

int main(){
    cin >> n >> k;

    arr.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    ll l = 1, r = 1e9, med = -1, answ = -1;
    while(l<=r){
        med = l + (r-l)/2;
        if(isOk(med)){
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