#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;

int main(){
	ll n, k;

	cin >> n >> k;

	if(n%2){
		//cout << "1 ";
		n--; k--;
	}

	while(true){
		if(k==1){
			cout << ((n==(n&-n)) ? "yes" : "no");
			break;
		}
		n-=2;
		k--;
		//cout << "1 ";
	}

	cout << '\n';
	return 0;
}
