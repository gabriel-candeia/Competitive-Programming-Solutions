#include<iostream>

using namespace std;

int main(){
	int n;
	int last;
	cin >> n;
	last = n;
	cout << n << ' ';
	for(int i=n/2;i;i--){
		if(last%i==0){
			cout << i << ' ';
			last = i;
		}
	}

	cout << "\n";

	return 0;
} 