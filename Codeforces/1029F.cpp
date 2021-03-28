#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll a, b, lst, lim, answ = 1e18;

    cin >> a >> b;
    lim = sqrt(a+b);
    
    for(ll j=0;j<=1;j++){
        for(ll i=1;i<=lim;i++){
            if(a%i==0)
                lst = i;
            if((a+b)%i==0 && a/lst <= (a+b)/i)
                answ = min(answ,2*((a+b)/i + i));
        }
        swap(a,b);
    }
    cout << answ <<'\n';

    return 0;
}