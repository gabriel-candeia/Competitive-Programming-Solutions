#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n;
	cin >> n;
	while(n!=1){
		printf("%lld ",n);
		if(n%2){
			n=3*n+1;
		}
		else{
			n/=2; 
		}		
	}
	printf("1\n");
	return 0;
}
