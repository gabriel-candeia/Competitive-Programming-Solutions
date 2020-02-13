#include<bits/stdc++.h>
#define N 200010
using namespace std;

int sieve[2*N];

void sieve_func(int n){
	for(int i=0;i<=n;i++){
		sieve[i] = 1;
	}
	sieve[0] = 0;
	sieve[1] = 0;
	for(int i=2;i<=n;i++){
		if(sieve[i]==1){	
			for(int j=2*i;j<=n;j+=i){
				sieve[j] = 0;
			}	
		}
	}
}

int main(){
	int n, sum=0;
	int n1=0, n2=0, temp;
	int current=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> temp;
		n1+=(temp==1);
		n2+=(temp==2);
	}
	sum=n1+n2*2;
	sieve_func(sum);
	while(current<sum){
		if(sieve[current+1]&&n1||n2==0){
			n1--;
			current++;
			cout << "1 ";
		}
		else{
			n2--;
			current+=2;
			cout << "2 ";
		}
	}
	cout << '\n';
	return 0;
}