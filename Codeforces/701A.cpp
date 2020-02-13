#include<bits/stdc++.h>
#define N 100+10
using namespace std;

int main(){
	int numbers[N];
	int n, soma, minimo, maximo;

	cin >> n;
	minimo = 110;
	maximo = 0;
	for(int i=0;i<n;i++){
		cin >> numbers[i];
		minimo = min(minimo,numbers[i]);
		maximo = max(maximo,numbers[i]);
	}

	soma = maximo+minimo;
	for(int i=0, j;i<n;i++){
		if(numbers[i]){
			for(j=i+1;j<n;j++){
				if(numbers[j]+numbers[i]==soma){
					break;
				}
			}
			numbers[j] = 0;
			cout << i+1 << ' ' << j+1<<'\n';
		}
	}

	return 0;
}