#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll p, a, b, c, t;
    cin >> t;
    while(t--){
        cin >> p >> a >> b >> c;
        ll answ = 1e18;
        if(p%a==0 || p%b==0 || p%c==0)
            answ = 0;
        cout << min({answ,a-p%a,b-p%b,c-p%c}) << '\n';
    }
    return 0;
}