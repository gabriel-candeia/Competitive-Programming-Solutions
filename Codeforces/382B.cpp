#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a, b, w, x, c;

bool isOk(ll med){
    ll c1, a1, b1;
    c1 = c-med;
    b1 = (b+med*x)%w;
    a1 = a - (b1+med*x)/w;
    return (c1<=a1);
}

int main(){
    

    cin >> a >> b >> w >> x >> c;
    ll delta = c-a;
    ll k;

    if(delta<=0){
        cout << 0 << '\n';
    }
    else{
        k = ceil((((c-a)*x-b+0.0)/(w-x+0.0)));
        printf("%lld\n",c-a+k);
    }

    return 0; 
}