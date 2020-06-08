#include<bits/stdc++.h>
#define ld long double
#define ll long long
using namespace std;

int main(){
    ll k, d, t, i, temp;
    ld td, answ, resto;

    cin >> k >> d >> t;

    temp = (d-k%d);
    if(temp==d){
        temp = 0;
    }

    td = k + (temp)/((ld) 2.0);
    i = t/td;

    resto = t - i*td;
    if(resto>k){
        resto = (resto-k)*2+k;
    }

    answ = (k + (temp))*i + resto   ;
    
    printf("%Lf\n",answ);

    return 0;
}