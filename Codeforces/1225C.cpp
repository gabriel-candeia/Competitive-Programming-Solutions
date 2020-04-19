#include<bits/stdc++.h>
#define ll long long
using namespace std;

int countOnes(ll n){
    int acm=0;
    while(n){
        acm+=n%2;
        n/=2;
    }
    return acm;
}

int countOnesUB(ll n){
    int acm=0, acm1=1;
    while(n){
        acm+=(n%2)*acm1;
        n/=2;
        acm1*=2;
    }
    return acm;
}

int main(){
    ll n, p;
    int temp;

    cin >> n >> p;
    for(int i=1;i<32;i++){
        if(countOnes(n-i*p)<=i && i<=countOnesUB(n-i*p)){
            cout << i <<'\n';
            return 0;
        }
    }

    cout << -1 << '\n';

    return 0;
}