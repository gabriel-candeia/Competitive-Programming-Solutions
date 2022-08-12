#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, x;

    cin >> n;

    x = n;
    ll pot = 1, answ = 0;
    while(x>1){
        answ += pot*(x/2);
        x = x/2 + x%2;
        pot = 2*pot;
    }

    cout << answ <<"\n";

    return 0;
}