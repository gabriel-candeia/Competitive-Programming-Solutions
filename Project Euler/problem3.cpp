//Largest Prime Factor
//after seeing the problem overview
#include<iostream>
#include<cmath>
#define ll long long int

using namespace std;

void fatorar(ll x){
	for(ll i=3;i<ceil(sqrt(x));i++){
		if(x%i==0){
			cout << i << "\n";
			while(x%i==0) x/=i; 
		}
	}
	if(x!=1) cout << x << "\n";
}

int main(){
	fatorar(600851475143); 
	return 0;
}




