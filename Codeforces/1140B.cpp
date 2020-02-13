#include<iostream>
#include<string>

using namespace std;

int main(){

	string ent;
	int n, tam, l, r;

	cin >> n;
	while(n--){
		cin >> tam >> ent;
		for(l=0;l<tam && ent[l]!='>';l++);
		for(r=tam-1;r>=0 && ent[r]!='<';r--);
		r = tam-r-1;
		cout << min(l,r) << '\n';
	}

	return 0;
}