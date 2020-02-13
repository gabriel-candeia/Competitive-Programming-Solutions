#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int func(ll x, ll y){
	while(x<y && x>3){
		if(x%2){
			x--;
		}
		else{
			x *= 3/2.0;
		}
	}
	return (x>=y);
}


int main(){
	int n;
	ll x, y;
	cin >> n;

	while(n--){
		cin >> x >> y;
		cout << ((func(x,y)||(x==2 && y==3)) ? "YES" : "NO") << '\n';
	}
	return 0;
}
