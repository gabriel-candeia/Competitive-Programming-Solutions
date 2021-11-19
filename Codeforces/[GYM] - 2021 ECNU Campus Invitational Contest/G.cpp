#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll m, n, g;

bool ok(ll x){
    return ((n-x+1)%g==0 || (n/m >= x-1));
}

int main(){
    int t;

    cin >> t;
    while(t--){
        cin >> n >> m;

        g = n/m;

        ll l = 2, r = n/m, med, answ = n/m+1;
        while(l<=r){
            med = (l+r)/2;
            if(ok(med)){
                answ = med;
                r = med-1;
            }
            else{
                l = med+1;
            }
        }

        cout << answ <<"\n";
    }

    return 0;
}