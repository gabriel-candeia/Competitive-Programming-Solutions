#include<iostream>
#include<string>

using namespace std;

int main(){
	int n;
	bool trocar = false;
	char digitos[9];
	string ent;

	cin >> n >> ent;
	for(int i=0;i<9;i++){
		cin >> digitos[i];
	}

	for(int i=0;i<n;i++){
		if((digitos[ent[i]-'1']>ent[i])||(trocar&&digitos[ent[i]-'1']==ent[i])){
			ent[i]=digitos[ent[i]-'1'];
			trocar = true;
		}
		else{
			if(trocar) break;
		}
	}

	cout << ent << '\n';
	return 0;
}