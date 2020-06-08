#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll max(ll a, ll b){
    return (a<b) ? b : a;
}

int main(){
    int n;
    ll answ = 0;
    vector<ll> a;

    cin >> n;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                answ = max(answ,a[i]|a[k]|a[j]);
            }        
        }    
    }

    cout << answ << '\n';

    return 0;
}