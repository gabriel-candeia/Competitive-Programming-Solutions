while True:
	try:
		n = int(input())
		a = 1
		cont = 1
		while(a!=0):
			a = (10*a+1)%n
			cont+=1
		print(cont)
	except:
		break

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, a, cont;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin>>n){
		a = 1;
		cont = 1;
		while(a){
			a = (10*a+1)%n;
			cont++;
		}
		printf("%d\n",cont);
	}
	return 0;
}
