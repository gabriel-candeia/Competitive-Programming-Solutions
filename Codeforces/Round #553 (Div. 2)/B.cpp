#include<iostream>

using namespace std;

int main(){
	int n, m;
	int values[600][600];
	int acm, diferentes;
	bool trocar = false;
	int linha;
	int aux;

	cin >> n >>m;
	acm = -1;
	for(int i=0;i<n;i++){
		diferentes = 0;
		for(int j=0;j<m;j++){
			cin >> values[i][j];
			diferentes+=(values[i][j]!=values[i][0]);
		}
		if(diferentes){
			trocar = true;
			linha = i;
		}
		if(acm==-1){
			acm = values[0][0];
		}
		else{
			acm^=values[i][0];
		}
	}

	if(acm){
		cout << "TAK\n";
		for(int i=0;i<n;i++){
			cout << 1 <<' ';
		}
		cout << '\n';
	}
	else if(trocar){
		cout << "TAK\n";
		for(int i=0;i<m;i++){
			if(values[linha][0]!=values[linha][i]){
				aux = i;
				break;
			}
		}
		for(int i=0;i<n;i++){
			if(i!=linha){
				cout << 1 <<' ';	
			}
			else{
				cout << aux+1 <<' ';		
			}
		}
		cout << '\n';
	}
	else{
		cout << "NIE\n";
	}
	return 0;
}