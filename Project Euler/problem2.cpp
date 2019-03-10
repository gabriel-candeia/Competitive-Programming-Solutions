//Even fibonacci numbers
#include<iostream>
#define ll long long int
#define M 10000
#define N 4000000

using namespace std;

int main(){
	ll fib[M], sum, i;
	fib[0] = 1;
	fib[1] = 1; 

	for(i=2, sum=0;fib[i-1]<N;i++){
		fib[i] = fib[i-1] + fib[i-2];
		sum += fib[i]*((i+1)%3==0);
		if(i%2){
			cout <<"aqui: "<< fib[i] << endl;
		}
	}

	cout << fib[2] << endl;
	cout << sum << endl;
	return 0;
}




def rot(x):
	for y in range(2,x):
		if(x%y==0):
			print(y)
			while(x%y==0):
				x = x/y

