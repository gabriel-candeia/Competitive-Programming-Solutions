#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, sqr;
    cin >> n;
    sqr = n*n;
    if(n<=2){
        cout << "-1" << '\n';
    }
    else if(n%2){
        cout << sqr/2 << ' ' << sqr/2+1 << '\n';
    }
    else{
        cout << sqr/4-1 << ' ' << sqr/4+1 << '\n';
    }

    return 0;
}