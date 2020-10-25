#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll josephus(ll n){
    if(n<=1)
        return 1;
    if(n%2)
        return 2*josephus(n/2)+1;
    return 2*josephus(n/2)-1;
}

int main(){
    ll n;
    cin >> n;
    cout << josephus(n) <<'\n';
    return 0;
}