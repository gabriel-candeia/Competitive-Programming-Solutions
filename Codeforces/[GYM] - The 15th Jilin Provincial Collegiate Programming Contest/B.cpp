#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll a, b, k;
    cin >> a >> b >> k;

    cout << a/b << ".";
    a = a%b;

    while(k--){
        a = 10*a;
        cout << a/b + (k==0 && (10*(a%b))/b>=5);
        a = a%b;
    }
    cout <<"\n";


    return 0;
}