#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool sign(ll x){
    return ((x>0) ? true : false);
}

int main(){
    ll t, n;

    cin >> t;
    while(t--){
        cin >> n;
        ll sum=0, current, last, x;

        cin >> last;
        current = last;
        for(int i=0;i<n-1;i++){
            cin >> x;
            if(sign(x)==sign(last)){
                current = max(current,x);
            }
            else{
                sum+=current;
                current = x;
            }
            last = x;
        }

        cout << sum + current <<'\n';
    }

    return 0;
}