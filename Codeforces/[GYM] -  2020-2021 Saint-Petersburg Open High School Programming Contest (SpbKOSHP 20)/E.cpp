#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll ceil(ll a, ll b){
    return (a/b + ((a%b)!=0));
}

int main(){
    ll n, lim, answ=1e18;

    cin >> n;
    lim = sqrt(n)+1;

    for(int i=1;i<=lim;i++)
        if(n%i==i/2 || n%i==i-i/2 || n%i==0)
            answ = min(answ,abs(i-ceil(n,i)));

    for(int j=1;j<=lim;j++){
        ll i = ceil(n,j);
        if(n%i==i/2 || n%i==i-i/2 || n%i==0)
            answ = min(answ,abs(i-ceil(n,i)));
    }
        
    cout << answ <<'\n';
    return 0;
}