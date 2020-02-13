#include<bits/stdc++.h>
#define N 200100
using namespace std;

int main(){
	int n, b, a;
	int maxa;
	int temp;
	int i,cont=0;

	cin >> n >> b >> maxa;
	a = maxa;

	for(i=0;i<n;i++){
		cin >> temp;

		if(temp==0){
			if(a) a--, cont++;
			else if(b) b--, cont++;
			else break;
		}
		else if(temp==1){
			if(b&&a!=maxa) b--, a++, cont++;
			else if(a) a--, cont++;
			else break;
		}

		if(a>maxa){
			a = maxa;
		}
	}

	cout << cont << "\n";

	return 0;
}