#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;
ll binpow(ll a, ll x){
    ll result = 1;
    while(x){
        if(x%2)
            result = (result*a)%mod;
        a = (a*a)%mod;
        x/=2;
    }
    return result;
}

int main(){
    string s;
    ll acm=0, cnt=-1;

    cin >> s;
    for(auto c:s){
        acm += ((c=='M') ? 1 : -1);
        cnt += (acm==0);
    }  

    cout << binpow(2,cnt) <<'\n';

    return 0;
}