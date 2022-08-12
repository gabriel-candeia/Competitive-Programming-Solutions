#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll a, b, c, delta;

    cin >> a >> b >> c;

    delta = b*b-4*a*c;
    ll raiz = sqrt(delta);
    if(raiz*raiz==delta){
        cout << "Y\n";
    }
    else{
        cout << "N\n";
    }

    return 0;
}