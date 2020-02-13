#include<bits/stdc++.h>

using namespace std;

bool qtd_cores(int cores[20]){
	int qtd = -1;
	int maximo;
	bool cond1 = true, cond2 = true;

	for(int i=1;i<=10;i++){
		if(cores[i]>qtd){
			maximo = i;
			qtd = cores[i];
		}
	}

	//remove 1 do maximo
	if(cores[maximo]!=0){
		cores[maximo]--;
	}
	for(int i=1;i<=10;i++){
		if(cores[i]!=qtd-1 && cores[i]!=0){
			cond1 = false;
		}
	}
	cores[maximo]++;

	//remove algúm elemento igual a 1
	int temp=-1;
	for(int i=1;i<=10;i++){
		if(cores[i]==1){
			temp = i;
			cores[i]--;
			break;
		}
	}
	if(temp==-1){
		return cond1;
	}
	qtd = -1;
	for(int i=1;i<=10;i++){
		qtd = max(qtd,cores[i]);
	}
	for(int i=1;i<=10;i++){
		if(cores[i]!=qtd && cores[i]!=0){
			cond2 = false;
		}
	}
	if(temp!=-1){
		cores[temp]++;	
	} 

	return cond1||cond2;
}

int main(){
	int n, m, maior;	
	int cores[20] = {0};


	cin >> n;
	maior = 0;

	for(int i=0;i<=10;i++){
		cores[i] = 0;
	}

	for(int i=0;i<n;i++){
		cin >> m;
		cores[m]++;
		if(qtd_cores(cores)){
			maior = i+1;
		}
	}	

	cout << maior << '\n';

	return 0;
}