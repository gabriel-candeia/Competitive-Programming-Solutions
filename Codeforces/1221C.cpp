#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll min(ll a, ll b){
    return (a<b) ? a : b;
}

ll abs1(ll a){
    return (a<0) ? -a : a;
}

int main(){
    ll q, c, m, x;

    cin >> q;
    while(q--){
        cin >> c >> m >> x;

        ll lim = min(m,c), rem = abs1(m-c)+x;

        if(rem>lim){
            cout << lim << '\n';
        }
        else{
            cout << rem+2*(lim-rem)/3 <<'\n';
        }

    }

    return 0;
}