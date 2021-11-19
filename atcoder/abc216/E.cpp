#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll sum(ll a, ll b){
    if((b-a+1)%2){
        return ((a+b)/2)*(b-a+1);
    }
    return ((b-a+1)/2)*(a+b);
}

int main(){
    ll n, k;
    vector<ll> arr;
    cin >> n >> k;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;
    
    sort(arr.rbegin(),arr.rend());
    arr.push_back(0);
    ll answ = 0;
    
    for(int i=0,j=1;i<n;i=j){
        for(;j<n && arr[i]==arr[j];j++);
        ll vezes = arr[i]-arr[j];
        if(vezes*j<k){
            answ += sum(arr[j]+1,arr[i])*j;
            k-=vezes*j;
        }
        else{
            ll completo = k/j, base = arr[i]-completo;
            answ += sum(arr[i]-completo+1,arr[i])*j;
            k = k%j;
            answ += base*k;
            break;
        }
        //cout << answ <<"\n";
    }

    cout << answ <<"\n";

    return 0;
}