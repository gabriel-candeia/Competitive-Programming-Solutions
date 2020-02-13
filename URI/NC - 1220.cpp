#include<iostream>
#define N int(1e3)+10
using namespace std;

int main(){
	double t, acm;
	int vet[N], med, n;

	while(cin >> n){
		med = 0;
		acm = 0;

		if(!n){
			break;
		}

		for(int i=0;i<n;i++){
			cin >> t;
			vet[i] = 100*t;
			med += vet[i];
		}
		med /= n;

		for(int i=0;i<n;i++){
			if(vet[i]>med){
				acm+=vet[i]-med;
			}
		}
		cout << med << "\n";
		printf("$%.2lf\n",acm/100);
	}

	return 0;
}