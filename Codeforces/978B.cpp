#include<iostream>
#include<string>

using namespace std;

int main(){
	int n, l, r;
	int acm = 0;
	string ent;

	cin >> n >> ent;
	for(l=0;l<n;l++){
		r = l;
		while(r<n&&ent[r]=='x') r++;
		if(r-l>=3){
			acm+= r-l-2;
		}
		l = r;
	}

	cout << acm << '\n';

	return 0;
}