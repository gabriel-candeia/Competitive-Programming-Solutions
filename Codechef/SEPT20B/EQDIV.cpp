#include<bits/stdc++.h>
#define ll long long
using namespace std;

string resp;

ll pot(ll a, ll b){
    ll answ = 1;
    while(b--)
        answ*=a;
    return answ;
}

ll dp(ll i, ll k,ll n){
	if(i>n)
		return 0ll;
	ll x = dp(i+1,k,n);
	if(abs(x+pot(i,k))<abs(x-pot(i,k))){
		resp[i-1] = '1';
		return x+pot(i,k);
    }
	return x-pot(i,k);
}

int main(){
    ll k, t, n;
    cin >> k >> t;
    while(t--){
        cin >> n;
        resp = string(n,'0');
        cout << abs(dp(1,k,n)) <<'\n';
        cout << resp <<'\n';
    }
    return 0;
}

