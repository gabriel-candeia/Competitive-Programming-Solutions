#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, l, r;
    vector<ll> restos;

    cin >> n >> l >> r;
    
    if(n==0){
        cout << 0 <<'\n';
        return 0;
    }

    ll x = n;
    while(x>0){
        restos.push_back(x%2);
        x/=2;
    }

    reverse(restos.begin(),restos.end());

    ll acm = 0;
    ll j=0, ptr;
    for(ll i=l;i<=r;i++){
        j = i; ptr=0;
        while(j%2==0){
            ptr++;
            j/=2;
        }
        acm+=restos[ptr];
    }

    cout << acm <<'\n';

    return 0;
}