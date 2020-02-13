#include<iostream>
#define ll unsigned long long int

using namespace std;

int contar1s(ll x){
	int cont=0;
	while(x){
		cont+=(x%2);
		x = (x >> 1);
	}
	return cont;
}

ll t, n, qtd, temp, Q;
ll x, y, op;
ll i1 = 1;
ll sets[10100];
int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for(ll i=0;i<n;i++){
			cin >> qtd;
			sets[i]=0;
			for(ll j=0;j<qtd;j++){
				cin >> temp;
				if((sets[i]&(i1 << temp))==0){
					sets[i] += (i1 << temp);
				}
			}
		}
		cin >> Q;	
		for(ll i=0;i<Q;i++){
			cin >> op >> x >> y;
			if(op==1){
				cout << contar1s(sets[x-1]&sets[y-1]) << endl;
			}
			else{
				cout << contar1s(sets[x-1]|sets[y-1]) << endl;
			}
		}
	}

	return 0;
}
