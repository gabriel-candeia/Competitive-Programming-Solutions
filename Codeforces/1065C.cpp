#include<iostream>
#define N 200100
#define ll long long int

using namespace std;

int main(){
	ll cont[N] = {0};
	ll n, k;
	ll minimo=200010, maximo=0, temp;
	// cont[i] conta quantas vezes o número i apareceu na entrada
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> temp;
		minimo = min(minimo,temp);
		maximo = max(maximo,temp);
		cont[temp]++;
	}
	//h é o valor em que estamos pensando em fazer o slice
	//lastCut é onde o último slice foi feito
	ll h=maximo+1, lastCut=maximo;
	//c guarda o número de elementos maiores que h
	ll c=0;
	//sum é a soma acumulada dos elementos maiores que h
	ll sum=0;
	//cost armazena o custo de fazer o slice para deixar todos com a altura de h-1
	ll cost=0;
	//slices guarda o número de cortes
	ll slices = 0;
	while(true){
		cost = sum - (h-1)*c;
		if(cost > k){
			// faz o corte
			slices++;
			lastCut = h;
			sum = h*c;
		}

		h--;
		if(h==minimo) break;
		sum += cont[h]*h;
		c+= cont[h];
	}	

	if(lastCut!=minimo) slices++;
	cout << slices << '\n';

	return 0;
}	