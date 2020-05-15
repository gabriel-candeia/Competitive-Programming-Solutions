#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll pow5(ll x){
    return 1ll*x*x*x*x*x;
}

int main(){
    ll x, a=0, b=0;

    cin >> x;
    for(ll i=0;i<4000;i++){
        for(ll j=i+1;j<4000;j++){
            if(x==pow5(j)-pow5(i)){
                a = j; b = i;
                break;
            }
            else if(x==pow5(j)-pow5(-i)){
                a = j; b = -i;
                break;
            }
            else if(x==pow5(-j)-pow5(i)){
                a = -j; b = i;
                break;
            }
        }
    }

    cout << a << " " << b <<'\n';   
    return 0;
}