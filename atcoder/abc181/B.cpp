#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, a, b;
    cin >> n;
    ll answ = 0;
    while(n--){
        cin >> a >> b;
        answ += (a+b)*(b-a+1)/2;
    }
    cout << answ <<'\n';

}