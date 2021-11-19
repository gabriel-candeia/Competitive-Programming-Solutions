#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    vector<ll> arr;
    ll x, sum=0;

    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x, sum+=x;
    cin >> x;

    ll answ = (x/sum)*n;
    x = x%sum;
    for(int i=0;x>=0;i++){
        x-=arr[i];
        answ++;
    }
    
    cout << answ <<"\n";

    return 0;
}