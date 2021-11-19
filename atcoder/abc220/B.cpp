#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll convert(string s, ll k){
    ll acm = 0;
    for(auto c:s){
        acm =  acm*k+c-'0';
    }
    return acm;
}

int main(){
    ll k, a, b;
    string s1, s2;

    cin >> k >> s1 >> s2;

    a = convert(s1,k);
    b = convert(s2,k);

    cout << a*b <<"\n";

    return 0;
}