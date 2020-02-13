#include<iostream>
#include<set>
#define ll long long int
using namespace std;

ll f(ll x){
	x ++;
	while(x%10==0){
		x = x/10;
		if(x==0){
			break;
		}
	}
	return x;
}

int main(){
	ll n;
	set<ll> reached;

	cin >> n;
	reached.insert(n);
	while(true){
		n = f(n);
		if(reached.find(n)==reached.end()){
			reached.insert(n);
		}
		else{
			break;
		}
	}

	cout << reached.size() << '\n';

	return 0;
}