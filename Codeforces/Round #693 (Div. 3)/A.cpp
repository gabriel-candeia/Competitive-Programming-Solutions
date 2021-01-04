#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        ll n, x, y;
        cin >> x >> y >> n;

        ll acm = 1, answ=1;
        while(x%2==0){
            x/=2;
            acm=acm*2;
        }
        answ = answ*acm;
        
        acm = 1;
        while(y%2==0){
            y/=2;
            acm=acm*2;
        }
        answ = answ*acm;

        if(answ>=n)
            cout << "YES\n";
        else
            cout << "NO\n";

    }
    return 0;
}