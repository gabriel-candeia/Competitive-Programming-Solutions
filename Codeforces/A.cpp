#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	int letras[26]={0};
	string ent;
	int answ;

	cin >> n >> k;
	cin >> ent;
	for(int i=0;i<n;i++){
		letras[ent[i]-'A']++;
	}

	answ = letras[0];
	for(int i=0;i<k;i++){
		answ = min(answ,letras[i]);
	}

	cout << answ*k << '\n';

	return 0;
}