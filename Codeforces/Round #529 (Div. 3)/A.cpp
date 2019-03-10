#include<iostream>
#include<string>
#define ll long long int
using namespace std;

int main(){
	string input;
	ll n, counter, inc;

	cin >> n >> input;

	for(counter=0, inc=1;counter<n;counter+=inc,inc++){
		cout << input[counter];
	}
	cout << '\n';
	return 0;
}

