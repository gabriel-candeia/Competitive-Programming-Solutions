#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll a, b, answ=1;
    cin >> a >> b;
    for(ll i=a+1;i<=b && answ;i++)
        answ = (answ*i)%10;
    cout << answ <<'\n';
    return 0;
}