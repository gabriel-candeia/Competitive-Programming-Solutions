#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	vector<string> lista;
	string temp;

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> temp;
		lista.push_back(temp);
	}

	sort(lista.begin(),lista.end());

	for(int i=0;i<n;i++){
		cout << lista[i] << "\n";
	}

	return 0;
}