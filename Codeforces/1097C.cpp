#include<bits/stdc++.h>
#define N 100100
using namespace std;

char aux;

int classifier(string ent){
	char stack[N];
	int topo=0;
	int cont =0;
	int lb =0;
	int rb = 0;
	for(int i=0;i<ent.size();i++){
		if(topo!=0&&stack[topo-1]=='('&&ent[i]==')'){
			topo--;
			lb--;
		}
		else{
			stack[topo++]=ent[i];
			if(ent[i]==')'){
				rb++;
			}
			else{
				lb++;
			}
		}
	}

	if(lb!=0&&rb!=0){
		return -1;
	}

	if(lb){
		aux = '(';
	}
	if(rb){
		aux = ')';	
	}
	return max(lb,rb);
}

int main(){
	map<int,int> sobrandoL;
	map<int,int> sobrandoR;
	int n, cont;
	int balanced=0;
	string ent;

	cin >> n;
	int pares =0;
	for(int i=0;i<n;i++){
		cin >> ent;
		cont = classifier(ent);
		if(cont==0){
			balanced++;
		}
		if(aux==')'){
			if(sobrandoL[cont]!=0){
				sobrandoL[cont]--;
				pares++;
			}else{
				sobrandoR[cont]++;
			}
		}
		else if(aux=='('){
			if(sobrandoR[cont]!=0){
				sobrandoR[cont]--;
				pares++;
			}else{
				sobrandoL[cont]++;
			}
		}

	}

	cout << pares+balanced/2 << '\n';

	return 0;
}