#include<iostream>
#include<string>

using namespace std;

int main(){
	int n, turnos, aux;
	string ent;
	string answ = "";
	bool poss;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> ent;

	turnos = (n-11)/2;
	aux = turnos;
	poss = false;
	for(int i=0;i<n;i++){
		if(ent[i]=='8'&&aux){
			aux--;
		}
		else{
			if(ent[i]=='8'){
				poss = true;
			}
			answ+=ent[i];
		}
	}

	if(!poss){
		cout << "NO\n";
	}
	else{
		aux = 0;
		for(int i=0;i<answ.size()&&answ[i]!='8';i++,aux++);
		if(aux<=turnos){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";		
		}
	}

	return 0;
}

