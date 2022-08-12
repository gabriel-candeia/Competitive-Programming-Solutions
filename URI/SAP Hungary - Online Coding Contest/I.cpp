#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, h, c, l;
    while(cin >> n){
        cin >> h >> c >> l;

        cout << fixed  << setprecision(4) << (n*l*sqrt(h*h+c*c)*1e-4)<<"\n";
    }


    return 0;
}