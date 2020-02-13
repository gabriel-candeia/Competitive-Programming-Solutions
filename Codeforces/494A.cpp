#include<iostream>

using namespace std;

int main(){
	string ent;
	int a=0;
	int cont =0;
	bool pos = true;
	int last = 0;
	int b;
	cin >> ent;

	for(int i=0;i<ent.size();i++){
		if(ent[i]=='#'){
			cont++;
			last = i;
			a--;
		}
		else if(ent[i]=='('){
			a++;
		}
		else{
			a--;
		}
		if(a<0){
			pos = false;
		}
	}
	b = 0;
	for(int i=0;i<ent.size();i++){
		if(i==last){
			b -= a;
		}
		if(ent[i]=='('){
			b++;
		}
		else{
			b--;
		}
		if(b<0){
			pos *= false;
		}
	}

	if(pos){
		for(int i=0;i<cont-1;i++){
			cout << 1 << '\n';
		}
		cout << a+1 << '\n';
	}
	else{
		cout << "-1\n";
	}

	return 0;
}