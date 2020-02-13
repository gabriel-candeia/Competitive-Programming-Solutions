#include<bits/stdc++.h>
using namespace std;

int fib(int n){
	int fib[100];
	fib[0] = 0;
	fib[1] = 1;
	for(int i=2;i<=n;i++){
		fib[i] = fib[i-1]+fib[i-2];
	}
	return fib[n];
}

int calls(int n){
	int fib[100];
	fib[0] = 0;
	fib[1] = 0;
	for(int i=2;i<=n;i++){
		fib[i] = fib[i-1]+fib[i-2]+2;
	}
	return fib[n];
}

int main(){
	int X, n;

	cin >> X;
	while(X--){
		cin >> n;
		printf("fib(%d) = %d calls = %d\n",n,calls(n),fib(n));	
	}

	return 0;
}

