#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;

    cin >> t;
    while(t--){
    ll n;
    ll answ = 0;

    cin >> n;
    for(int i=0;i<n;i++){
        ll x;
        
        cin >> x;
        
        if(x%(n+1)==0)
            answ += x/(n+1);
        else
            answ += x*(n+1);
    }
    cout << answ <<"\n";
    }
    return 0;
}