#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        ll a, b, c;
        cin >> a >> b >> c;

        ll answ = ceil(sqrt(abs(b-a)*abs(b-a) + c*c));
        cout << answ <<"\n";
    }

    return 0;
}