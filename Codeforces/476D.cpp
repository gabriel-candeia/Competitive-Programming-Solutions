#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, t;
	cin >> n >> t;

	cout << (6*(n-1)+5)*t << '\n';
	for(int i=0;i<n;i++){
		cout << (6*(i) + 1)*t << ' ' << (6*(i) + 2)*t << ' ' << (6*(i) + 3)*t << ' ' << (6*(i) + 5)*t << '\n';
	}

	return 0;
}