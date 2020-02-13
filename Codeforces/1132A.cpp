#include<iostream>
#define ll long long int
using namespace std;

int main(){
	ll c1, c2, c3, c4;
	bool poss = false;

	cin >> c1 >> c2 >> c3 >> c4;

	if((c1==c4) && ((c1!=0)||c3==0)){
		poss=true;
	}

	cout << poss << '\n';

	return 0;
}