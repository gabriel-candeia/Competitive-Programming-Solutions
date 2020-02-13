#include<iostream>
#include<cmath>
#define ll long long int
using namespace std;

int main(){
	ll n, s, d, last;

	cin >> n;
	last = 0;

	for(ll i=0;i<n;i++){
		cin >> s >> d;
		if(s>last){
			last = s;
		}
		else{
			last = ceil((last-s)*1.0/d)*d+s;
		}
		last++;
	}

	cout << last-1 << '\n';
	return 0;
}