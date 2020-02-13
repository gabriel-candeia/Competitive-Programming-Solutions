#include<iostream>
#include<cmath>

#define ll long long int

using namespace std;

int main(){
	ll n, t;
	ll s, d;
	ll firstbus, wait;
	ll m, mwait;
	cin >> n >> t;

	mwait = -1;	
	for(int i=0;i<n;i++){
		cin >> s >> d;
		if(t>s){
			firstbus = s+ceil((t-s)*1.0/d)*d;	
		}
		else{
			firstbus = s;
		}
		wait = firstbus-t;	
		if(wait<mwait || mwait==-1){
			mwait = wait;
			m = i+1;
		}
	}

	cout << m << '\n';

	return 0;
}