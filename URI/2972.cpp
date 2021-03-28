#include<bits/stdc++.h>
#define ll long long
using namespace std;

//usa o teorema de lucas

int main(){ 
    ll n;
    cin >> n;
    cout << (1ll<<__builtin_popcountll(n)) << '\n';
    return 0;
}