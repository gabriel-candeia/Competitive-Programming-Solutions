#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll a, b, c, d, maxnum;

	cin >> a >> b >> c >> d;
	maxnum = a;
	if(b>maxnum){
		maxnum = b;
	}
	if(c>maxnum){
		maxnum = c;
	}
	if(d>maxnum){
		maxnum = d;
	}

	if(maxnum-a){
		cout << maxnum-a <<' ';
	}
	if(maxnum-b){
		cout << maxnum-b <<' ';
	}
	if(maxnum-c){
		cout << maxnum-c <<' ';
	}
	if(maxnum-d){
		cout << maxnum-d <<' ';
	}
	cout << '\n';
	return 0;
}