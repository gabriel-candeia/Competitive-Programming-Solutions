#include<bits/stdc++.h>
#define ld long double
using namespace std;

int main(){
    ld m;

    cin >> m;

    ld a0, a1;
    for(double j=-1;;j+=M_PI/m){
        a0 = j;
        for(int i=0;i<100;i++){
            a1 = a0 - (a0-cos(m*a0))/(1.0*(1+m*sin(m*a0)));
            a0 = a1;
            if(abs(cos(a1*m)-a1)<1e-8)
                break;
        }
        if(abs(cos(a1*m)-a1)<1e-10)
            break;
    }

    cout <<fixed << setprecision(20) <<  a1 << "\n";
    //cout << cos(a1*m)-a1 <<'\n';

    return 0;
}