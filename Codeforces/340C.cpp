#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int main(){
    int n;
    vector<ll> arr;

    cin >> n;
    arr.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());
    ll answ=0, maiores, menores;
    for(int i=0;i<n;i++){
        menores = i;
        maiores = n-i-1;

        answ+=2ll*(menores-maiores)*arr[i];
        answ+=arr[i];
    }
    ll temp = gcd(answ,n);
    cout << answ/temp <<  " " << n/temp << '\n';

    return 0;
}