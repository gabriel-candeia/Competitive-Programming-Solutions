#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, a=1, b=1;
    string s;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> s;
        if(s=="AND")
            a = 2*a+b;
        else
            b = 2*b+a;
    }
    cout << b <<'\n';

    return 0;
}