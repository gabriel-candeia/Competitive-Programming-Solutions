#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, m;	

	cin >> n >> m;
	if(n==m){
		cout << 0 <<'\n';
	}
	else if(m<=1){
		cout << 1 <<'\n';
	}
	else{
		cout << min(n-m,m) << '\n';
	}

	return 0;
}