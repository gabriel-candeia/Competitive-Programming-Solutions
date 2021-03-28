#include<bits/stdc++.h>
#define ld double
using namespace std;

int main(){
    int n, answ=0;
    ld acm = 1;

    cin >> n;

    for(answ=0;acm>0.5;answ++)
        acm *= (n-answ)/(1.0*n);
    
    cout << answ <<'\n';

    return 0;
}