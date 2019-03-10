//Multiples of 3 and 5
#include<iostream>
#define ll long long int
#define N 15

using namespace std;

int main(){

	ll sum3, sum5, sum15;

	//Sum of all multiples of 3 up to N
	sum3 = (N-N%3)*(N/3+1)/2;
	//Sum of all multiples of 5 up to N
	sum5 = (N-N%5)*(N/5+1)/2;
	//Sum of all multiples of 15 up to N
	sum15 = (N-N%15)*(N/15+1)/2;
	//Sum of all multiples of 3 and 5 up to N
	cout << (sum3+sum5-sum15) << "\n"; 
	return 0;
}




